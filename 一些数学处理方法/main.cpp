#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/**
 *   一些数学上的常用操作
 */
int main() {
    /**
     *  指数
     */
     cout << pow(2, 10) << endl;
     /**
      *  对数
      */
      cout << log(10) << endl; // 自然对数
      cout << log10(10) <<endl; // 以10为底的对数
      cout << log2(1024) << endl; // 以2为底的对数
      cout << (log2(9)/log2(3)) << endl; // 使用换底公式解决一般的求解问题。
      /**
       * 开根号
       */
       cout << sqrt(9) << endl;
       cout << pow(27, 1.0/3) << endl; // 可以用 pow 实现开任意方根

       /**
        *  一些cout 输出格式技巧
        */
        cout << setprecision(4) << 0.012123 <<endl; // 保留有效数字的位数
        cout << scientific <<1.123213 <<endl ; // 以科学计数法输出


       return 0;
}