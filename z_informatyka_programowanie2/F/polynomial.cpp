#include "cstdarg"
#include "iostream"

class POLYNOMIAL {
   public:
    ~POLYNOMIAL() {
        integerNode* cur = head;
        while (cur) {
            integerNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    struct integerNode {
        integerNode* next = nullptr;
        int integral;
    };
    integerNode* head = nullptr;
};

std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c) {
    os << "( ";
    for (POLYNOMIAL::integerNode* cur = c.head; cur; cur = cur->next) {
        os << cur->integral;
        cur->next ? os << ", " : os << " )"; //its last ? 
    }
    return os;
}

std::istream& operator>>(std::istream& is, POLYNOMIAL& c) {
    int degree;
    is >> degree;
    POLYNOMIAL::integerNode* prev = nullptr;
    for (int i = 0; i <= degree; ++i) {
        POLYNOMIAL::integerNode* pol = new POLYNOMIAL::integerNode;
        is >> pol->integral;
        prev ? prev->next = pol : c.head = pol;  // its first ?
        prev = pol;
    }
    return is;
}

