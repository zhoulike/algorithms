class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < 5 && num2.size() < 5)
            return itoa(atoi(num1.c_str()) * atoi(num2.c_str()));

        string x_l(num1.begin(), num1.begin() + num1.size() / 2),
               x_r(num1.begin() + num1.size() / 2, num1.end()),
               y_l(num2.begin(), num2.begin() + num2.size() / 2),
               y_r(num2.begin() + num2.size() / 2, num2.end());
        int shift_x = num1.size() - num1.size() / 2,
            shift_y = num2.size() - num2.size() / 2;

        string p1 = shift(multiply(x_l, y_l), shift_x + shift_y),
               p2 = shift(multiply(x_l, y_r), shift_x),
               p3 = shift(multiply(x_r, y_l), shift_y),
               p4 = multiply(x_r, y_r);
        
        return add(add(add(p1, p2), p3), p4);
    }
private:
    string itoa(int num)
    {
        stringstream sstrm;
        sstrm << num;
        return sstrm.str();
    }

    string shift(string num, int n)
    {
        if (atoi(num.c_str()) == 0)
            return "0";
        else
            return num + string(n, '0');
    }

    string add(string num1, string num2)
    {
        string ans;
        int carry = 0;
        auto iter1 = num1.rbegin(), iter2 = num2.rbegin();
        for (;iter1 != num1.rend() && iter2 != num2.rend(); ++iter1, ++iter2) {
            int n1 = *iter1 - '0', n2 = *iter2 - '0';
            ans.push_back((n1 + n2 + carry) % 10 + '0');
            carry = (n1 + n2 + carry) / 10;
        }
        
        while (iter1 != num1.rend()) {
            int n1 = *iter1 - '0' + carry;
            ans.push_back(n1 % 10 + '0');
            carry = n1 / 10;
            ++iter1;
        }
        
        while (iter2 != num2.rend()) {
            int n2 = *iter2 - '0' + carry;
            ans.push_back(n2 % 10 + '0');
            carry = n2 / 10;
            ++iter2;
        }
        
        if (carry == 1)
            ans.push_back('1');
            
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
