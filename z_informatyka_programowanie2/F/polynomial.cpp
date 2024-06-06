#include "cstdarg"
#include "iostream"

class POLYNOMIAL {
   public:
    POLYNOMIAL(){};
    POLYNOMIAL(int degree, ...) {
        va_list args;
        va_start(args, degree);
        POLYNOMIAL::integerNode* prev = nullptr;
        for (int i = 0; i <= degree; i++) {
            POLYNOMIAL::integerNode* cur = new POLYNOMIAL::integerNode;
            cur->coefficient = va_arg(args, int);
            prev ? prev->next = cur : head = cur;  // its first ?
            prev = cur;
        }
        va_end(args);
    }

    ~POLYNOMIAL() {
        integerNode* cur = head;
        while (cur) {
            integerNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

   public:
    struct integerNode {
        integerNode* next = nullptr;
        int coefficient;
    };
    integerNode* head = nullptr;
};

std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c) {
    os << "( ";
    for (POLYNOMIAL::integerNode* cur = c.head; cur; cur = cur->next) {
        os << cur->coefficient;
        cur->next ? os << ", " : os << " )";  // its last ?
    }
    return os;
}

std::istream& operator>>(std::istream& is, POLYNOMIAL& c) {
    int degree;
    is >> degree;
    POLYNOMIAL::integerNode* prev = nullptr;
    for (int i = 0; i <= degree; ++i) {
        POLYNOMIAL::integerNode* cur = new POLYNOMIAL::integerNode;
        is >> cur->coefficient;
        prev ? prev->next = cur : c.head = cur;  // its first ?
        prev = cur;
    }
    return is;
}