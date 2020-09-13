/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.alibaba.cloud.dubbo.gateway;

import java.util.HashMap;
import java.util.Map;

import com.alibaba.cloud.dubbo.http.MutableHttpServerRequest;
import com.alibaba.cloud.dubbo.metadata.DubboRestServiceMetadata;
import com.alibaba.cloud.dubbo.metadata.RequestMetadata;
import com.alibaba.cloud.dubbo.metadata.RestMethodMetadata;
import com.alibaba.cloud.dubbo.metadata.repository.DubboServiceMetadataRepository;
import com.alibaba.cloud.dubbo.service.DubboGenericServiceExecutionContext;
import com.alibaba.cloud.dubbo.service.DubboGenericServiceExecutionContextFactory;
import com.alibaba.cloud.dubbo.service.DubboGenericServiceFactory;
import org.apache.commons.lang3.StringUtils;

import org.apache.dubbo.rpc.service.GenericException;
import org.apache.dubbo.rpc.service.GenericService;

import org.springframework.http.server.reactive.ServerHttpResponse;
import reactor.core.publisher.Mono;

import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.cloud.gateway.filter.GlobalFilter;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.web.server.ServerWebExchange;

import static org.apache.commons.lang.StringUtils.substringAfter;
import static org.apache.commons.lang3.StringUtils.substringBetween;

public class DubboGatewayFilter implements GlobalFilter {

	private final DubboServiceMetadataRepository repository;

	private final DubboGenericServiceFactory serviceFactory;

	private final DubboGenericServiceExecutionContextFactory contextFactory;

	private final Map<String, Object> dubboTranslatedAttributes = new HashMap<>();

	public DubboGatewayFilter(DubboServiceMetadataRepository repository,
			DubboGenericServiceFactory serviceFactory,
			DubboGenericServiceExecutionContextFactory contextFactory) {
		this.repository = repository;
		this.serviceFactory = serviceFactory;
		this.contextFactory = contextFactory;
		this.dubboTranslatedAttributes.put("protocol", "dubbo");
		this.dubboTranslatedAttributes.put("cluster", "failover");
	}

	public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {

		ServerHttpRequest request = exchange.getRequest();

		String serviceName = resolveServiceName(request);

		String restPath = substringAfter(request.getPath().value(), serviceName);

		// 初始化 serviceName 的 REST 请求元数据
		repository.initializeMetadata(serviceName);
		// 将 HttpServletRequest 转化为 RequestMetadata
		RequestMetadata clientMetadata = buildRequestMetadata(request, restPath);

		DubboRestServiceMetadata dubboRestServiceMetadata = repository.get(serviceName,
				clientMetadata);

		if (dubboRestServiceMetadata == null) {
			// if DubboServiceMetadata is not found, executes next
			return chain.filter(exchange);
		}

		RestMethodMetadata dubboRestMethodMetadata = dubboRestServiceMetadata
				.getRestMethodMetadata();

		GenericService genericService = serviceFactory.create(dubboRestServiceMetadata,
				dubboTranslatedAttributes);

		// TODO: Get the Request Body from HttpServletRequest
		byte[] body = getRequestBody(request);

		MutableHttpServerRequest httpServerRequest = new MutableHttpServerRequest(request,
				body);

		DubboGenericServiceExecutionContext context = contextFactory
				.create(dubboRestMethodMetadata, httpServerRequest);

		Object result = null;
		GenericException exception = null;

		try {
			result = genericService.$invoke(context.getMethodName(),
					context.getParameterTypes(), context.getParameters());

			ServerHttpResponse response = exchange.getResponse();
//			response.writeAndFlushWith(Publisher.)

		}
		catch (GenericException e) {
			exception = e;
		}

		return Mono.empty();
	}

	private String resolveServiceName(ServerHttpRequest request) {
		// /g/{app-name}/{rest-path}
		String requestURI = request.getPath().value();
		// /g/
		String servletPath = request.getPath().contextPath().value();

		String part = StringUtils.substringAfter(requestURI, servletPath);

		String serviceName = substringBetween(part, "/", "/");

		return serviceName;
	}

	private byte[] getRequestBody(ServerHttpRequest request) {
		return new byte[0];
	}

	private RequestMetadata buildRequestMetadata(ServerHttpRequest request,
			String restPath) {
		RequestMetadata requestMetadata = new RequestMetadata();
		requestMetadata.setPath(restPath);
		requestMetadata.setMethod(request.getMethod().toString());
		requestMetadata.setParams(request.getQueryParams());
		requestMetadata.setHeaders(request.getHeaders());
		return requestMetadata;
	}

}
