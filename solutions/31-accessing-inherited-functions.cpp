/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>

class A {
    public:
        A() {
            callA = 0;
        }
    private:
        int callA;
        void inc() {
            callA++;
        }

    protected:
        void func(int & a) {
            a = a * 2;
            inc();
        }
    public:
        int getA() {
            return callA;
        }
};

class B {
    public:
        B() {
            callB = 0;
        }
    private:
        int callB;
        void inc() {
            callB++;
        }
    protected:
        void func(int & a) {
            a = a * 3;
            inc();
        }
    public:
        int getB() {
            return callB;
        }
};

class C {
    public:
        C() {
            callC = 0;
        }
    private:
        int callC;
        void inc() {
            callC++;
        }
    protected:
        void func(int & a) {
            a = a * 5;
            inc();
        }
    public:
        int getC() {
            return callC;
        }
};

class D : protected A, B, C {
	int val;
	public:
	//Initially val is 1
    D() {
        val = 1;
    }

    //Implement this function
    void update_val(int new_val) {
        while (new_val != 0) {
            if (new_val % 2 == 0) {
                A::func(val);
                new_val /= 2;
            } else if (new_val % 3 == 0) {
                B::func(val);
                new_val /= 3;
            } else if (new_val % 5 == 0) {
                C::func(val);
                new_val /= 5;
            } else {
                break; // If new_val is not divisible by 2, 3, or 5, exit the loop
            }
        }
    }

    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val) {
    update_val(new_val);
    std::cout << "Value = " << val << std::endl
              << "A's func called " << getA() << " times" << std::endl
              << "B's func called " << getB() << " times" << std::endl
              << "C's func called " << getC() << " times" << std::endl;
}

int main() {
    D d;
    int new_val;
    std::cin >> new_val;
    d.check(new_val);
    return 0;
} // end of main
