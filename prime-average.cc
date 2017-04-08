#include <node.h>
#include <math.h>

namespace demo {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    bool checkIsPrime(int n) {
        int j;
        bool isPrime = true;

        if (n == 1) {
            return false;
        }

        double nSqrt = sqrt(n);

        for(j = 2; j <= nSqrt; ++j)
        {
            if(n % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }


    void calculate(const FunctionCallbackInfo<Value>& args)
    {
        double f = 0;
        int i;
        double n = args[0]->NumberValue();

        for (i = 1; i <= n; ++i) {
            if (checkIsPrime(i)) {
                f += (i - f) / i;
            }
        }

        args.GetReturnValue().Set(f);
    }


    void init(Local<Object> exports) {
      NODE_SET_METHOD(exports, "calculate", calculate);
    }


    NODE_MODULE(addon, init)
}
