// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3018/

class Solution {
    // 0 to 255, no leading number
    bool get0to255(string& ip, int& i)
    {

        if (i<0|| i>=ip.size()) return false;

        if (!isdigit(ip[i])) return false;
        int j=i;
        while (j<ip.size()&& isdigit(ip[j]) ) // mistake: the order!!
        {
            j++;
            // optimize: jump out
            if (j-i>3) return false;
        }

        string num_str= ip.substr(i, j-i);
        int num= stoi (num_str);

        if (num>255) return false;

        // leading 0
        if (to_string(num).size()!= num_str.size()) return false;

        // mistake: always forgot this!!
        i=j;
        return true;
    }

    bool validIPv4(string ip)
    {
        // optimize:
        if (ip.size()>15) return false;

        ip.push_back('.'); //padding last .
        int i=0;
        //4 segments
        for (int r=0; r<4; r++)
        {
            if (!get0to255 (ip,i))
                return false;
            if (i>=ip.size() || ip[i]!='.')
                return false;
            i++;
        }

        return i== ip.size();
    }
//--------------------------------
    bool isHex(char c)
    {
        return c>='0'&&c<='9' || c>='a'&&c<='f' || c>='A'&&c<='F';
    }

    // 0-9 a-f or A-F
    bool get1to4Hex(string &ip, int&i)
    {
        if (i<0|| i>=ip.size()) return false;

        if (!isHex(ip[i])) return false;

        int j=i;
        while (j<ip.size() && isHex(ip[j]))
        {
            j++;
            // optimize: jump out
            if (j-i>4) return false;
        }

        string num_str= ip.substr(i, j-i);

        if (num_str.size()>4) return false;

        i=j;

        return true;
    }

    bool validIPv6(string ip)
    {
         // optimize:
        if (ip.size()>39) return false;

        ip.push_back(':');
        int i=0;

        for (int r=0; r<8; r++)
        {
            if (!get1to4Hex (ip,i))
                return false;
            if (i>=ip.size() || ip[i]!=':')
                return false;
            i++;
        }

        return i== ip.size();
    }
public:
    string validIPAddress(string IP) {
        if (validIPv4(IP))
            return "IPv4";
        else if (validIPv6(IP))
            return "IPv6";

        return "Neither";
    }
};
