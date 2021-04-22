select a.name Employee from employee a
join Employee b on b.id = a.Managerid
where a.salary > b.salary 
