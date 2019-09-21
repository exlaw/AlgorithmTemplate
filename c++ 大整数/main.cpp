#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class BigNum{
public:
    string value;

    BigNum(int v){
        stringstream ss;
        ss << v;
        value = ss.str();
    }
    BigNum(string v){
        value = v;
    }

    BigNum operator = (BigNum& b){
        return BigNum(b.value);
    }

    void setValue(string v){
        value = v;
    }

    bool operator < (BigNum& b) const {
        if(value.length() < b.value.length()){
            return true;
        }else if(value.length() > b.value.length()){
            return false;
        }else{
            for(int i = 0; i < value.length(); i++){
                if(value[i] < b.value[i]){
                    return true;
                }else if(value[i] > b.value[i]){
                    return false;
                }
            }
        }
        return false;
    }

    BigNum operator *(BigNum b){
        int length = b.value.length() * value.length() + 2;
        string result(length, '0');
        for(int i = value.length() - 1; i >= 0; i--){
            for(int j = b.value.length() - 1; j >= 0; j--){
                int pos = length - (value.length() - i) * (b.value.length() - j);
                int sum = (value[i] - '0') * (b.value[j] - '0') + result[pos] - '0';
                result[pos - 1] += sum/10;
                result[pos] = sum%10 + '0';
            }
        }
        int count =  0;
        while(result[count] == '0'){
            count ++;
        }
        return BigNum(result.substr(count, length - count));
    }

    BigNum operator -(BigNum b){
        string result(value.length(), '0');
        int borrow = 0;
        int i = value.length() - 1;
        int j = b.value.length() - 1;
        int k = value.length() - 1;
        while(j >= 0){
            int sum = value[i--] - '0' - (b.value[j--] - '0') - borrow;
            if(sum < 0){
                sum += 10;
                borrow = 1;
            }else{
                borrow = 0;
            }
            result[k--] = sum + '0';
        }
        while(i>=0){
            int sum = value[i--] - '0' - borrow;
            if(sum < 0){
                sum += 10;
                borrow = 1;
            }else{
                borrow = 0;
            }
            result[k--] = sum + '0';
        }
        int count = 0;
        while(result[count] == '0'){
            count ++;
        }
        return BigNum(result.substr(count, value.length() - count));
    }

    BigNum operator / (BigNum b){
        BigNum a(value);
        string result("");
        int length = 1;
        while(b.value.length() < a.value.length()){
            b.value += '0';
            length ++;
        }
        for(int i = 0; i < length; i++){
            int count = 0;
            while(b < a){
                BigNum temp = a - b;
                a.setValue(temp.value);
                count ++;
            }
            if(!(i == 0 && length != 1))
                result += (count + '0');
            b.value = b.value.substr(0, b.value.length() - 1);
        }
        return BigNum(result);
    }

    BigNum operator + (BigNum& b){
        int length = value.length() > b.value.length() ? value.length() + 1 : b.value.length() + 1;
        string result(length, '0');
        int i = value.length() - 1;
        int j = b.value.length() - 1;
        int k = length - 1;
        while(i >= 0 && j >= 0){
            int sum = value[i--] - '0' + b.value[j--] -'0' + result[k] - '0';
            result[k - 1] += sum/10;
            result[k] = sum%10 + '0';
            k --;
        }
        while(i >= 0){
            int sum = value[i--] - '0' + result[k] - '0';
            result[k - 1] += sum/10;
            result[k] = sum%10 + '0';
            k --;
        }
        while( j >= 0){
            int sum =  b.value[j--] -'0' + result[k] - '0';
            result[k - 1] += sum/10;
            result[k] = sum%10 + '0';
            k --;
        }
        int count = 0;
        while(result[count] == '0'){
            count ++;
        }
        return BigNum(result.substr(count, length-count));
    }
    int operator %(int v){
        int k = 0;
        for(int i = 0; i < value.length(); i++){
            k = ((k * 10)%v + value[i] - '0' )%v;
        }
        return k;
    }
};

int main() {
    BigNum b(3);
    BigNum c(8);
    BigNum temp = b*c;
    cout << temp.value << endl;
    BigNum temp1 = c - b;
    cout << temp1.value << endl;
    BigNum temp2 = c / b;
    cout << temp2.value <<endl;
    BigNum temp3 = c + b;
    cout << temp3.value <<endl;
    int a = c%3;
    cout << a << endl;
    return 0;
}