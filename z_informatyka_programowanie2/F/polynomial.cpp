#include "cstdarg"
#include "iostream"

class POLYNOMIAL {
   public:
    struct integerNode {
        integerNode* next = nullptr;
        int coefficient;
    };
    integerNode* head = nullptr;

   public:
    POLYNOMIAL(){};
    POLYNOMIAL(const POLYNOMIAL& toClone) {
        POLYNOMIAL::integerNode* prev = nullptr;
        for (POLYNOMIAL::integerNode* other = toClone.head; other; other = other->next) {
            POLYNOMIAL::integerNode* newNode = new POLYNOMIAL::integerNode;
            newNode->coefficient = other->coefficient;
            prev ? prev->next = newNode : head = newNode;
            prev = newNode;
        }
    };
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
        CheckForReduce();
    }
    ~POLYNOMIAL() {
        clear();
    }

   public:  // operators overload
    POLYNOMIAL operator=(const POLYNOMIAL& other) {
        clear();
        head = new POLYNOMIAL::integerNode;
        head->coefficient = 0;
        *this += other;
        return *this;
    }

    POLYNOMIAL operator+(const POLYNOMIAL& other) {
        POLYNOMIAL res(*this);
        res += other;
        return res;
    }

    POLYNOMIAL operator+=(const POLYNOMIAL& other) {
        integerNode* mineCurrent = head;
        integerNode* otherCurrent = other.head;
        while (otherCurrent) {
            mineCurrent->coefficient += otherCurrent->coefficient;
            otherCurrent = otherCurrent->next;
            if (!mineCurrent->next) break;
            mineCurrent = mineCurrent->next;
        }
        while (otherCurrent) {
            POLYNOMIAL::integerNode* newNode = new POLYNOMIAL::integerNode;
            newNode->coefficient = otherCurrent->coefficient;
            mineCurrent->next = newNode;
            mineCurrent = mineCurrent->next;
            otherCurrent = otherCurrent->next;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator-(const POLYNOMIAL& other) {
        POLYNOMIAL res(*this);
        res -= other;
        return res;
    }

    POLYNOMIAL operator-=(const POLYNOMIAL& other) {
        integerNode* mineCurrent = head;
        integerNode* otherCurrent = other.head;
        while (otherCurrent) {
            mineCurrent->coefficient -= otherCurrent->coefficient;
            otherCurrent = otherCurrent->next;
            if (!mineCurrent->next) break;
            mineCurrent = mineCurrent->next;
        }
        while (otherCurrent) {
            POLYNOMIAL::integerNode* newNode = new POLYNOMIAL::integerNode;
            newNode->coefficient = (otherCurrent->coefficient * -1);
            mineCurrent->next = newNode;
            mineCurrent = mineCurrent->next;
            otherCurrent = otherCurrent->next;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator*(const POLYNOMIAL& other) {
        POLYNOMIAL res(*this);
        res *= other;
        return res;
    }

    POLYNOMIAL operator*=(const POLYNOMIAL& other) {
        integerNode* otherCurrent = other.head;

        int multiplicationDegree = 0;
        POLYNOMIAL res(0, 0);
        POLYNOMIAL partialProduct;
        while (otherCurrent) {
            partialProduct = *this;
            for (integerNode* cur = partialProduct.head; cur; cur = cur->next) {
                cur->coefficient *= otherCurrent->coefficient;
            }

            for (int i = 0; i < multiplicationDegree; i++) {
                integerNode* prevZeroIntergral = new integerNode;
                prevZeroIntergral->next = partialProduct.head;
                prevZeroIntergral->coefficient = 0;
                partialProduct.head = prevZeroIntergral;
            }
            multiplicationDegree++;
            res += partialProduct;
            otherCurrent = otherCurrent->next;
        }
        *this = res;
        return *this;
    }

    POLYNOMIAL operator/(const POLYNOMIAL& other) {
        // todo
        return *this;
    }

    POLYNOMIAL operator/=(const POLYNOMIAL& other) {
        // todo
        return *this;
    }

    POLYNOMIAL operator%(const POLYNOMIAL& other) {
        // todo
        return *this;
    }

    POLYNOMIAL operator%=(const POLYNOMIAL& other) {
        // todo
        return *this;
    }

    POLYNOMIAL operator>>(int amount) {
        POLYNOMIAL res = *this;
        res >>= amount;
        return res;
    }

    POLYNOMIAL operator<<(int amount) {
        POLYNOMIAL res = *this;
        res <<= amount;
        return res;
    }

    POLYNOMIAL operator>>=(int amount) {
        while (amount--) {
            POLYNOMIAL::integerNode* newIntegral = new integerNode;
            newIntegral->coefficient = 0;
            newIntegral->next = head;
            head = newIntegral;
        }
        return *this;
    }

    POLYNOMIAL operator<<=(int amount) {
        while (amount-- && head) {
            POLYNOMIAL::integerNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        return *this;
    }

    POLYNOMIAL& operator++() {
        for (integerNode* cur = head; cur; cur = cur->next) {
            ++cur->coefficient;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator++(int) {
        POLYNOMIAL temp = *this;
        ++(*this);
        return temp;
    }

    POLYNOMIAL& operator--() {
        for (integerNode* cur = head; cur; cur = cur->next) {
            --cur->coefficient;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator--(int) {
        POLYNOMIAL temp = *this;
        --(*this);
        return temp;
    }



   private:  // private methods
    void clear() {
        integerNode* cur = head;
        while (cur) {
            integerNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }

    void CheckForReduce() {
        removeLeadingZeros();
        int minValue = minimalNonZeroCoefficient();
        for (int reducer = minValue; reducer > 1; reducer--) {
            if (minValue % reducer != 0) continue;
            bool toReduce = true;
            for (POLYNOMIAL::integerNode* cur = head; cur && toReduce; cur = cur->next) {
                if (cur->coefficient % reducer != 0) toReduce = false;
            }
            if (toReduce) {
                for (POLYNOMIAL::integerNode* cur = head; cur; cur = cur->next) {
                    cur->coefficient /= reducer;
                }
                minValue /= reducer;
                reducer = minValue + 1;
            }
        }
    }

    int minimalNonZeroCoefficient() {
        int minValue = INT_MAX;
        for (integerNode* cur = head; cur; cur = cur->next) {
            if (cur->coefficient != 0 && minValue > abs(cur->coefficient)) minValue = abs(cur->coefficient);
        }
        return minValue;
    }

    void removeLeadingZeros(){
        integerNode *lastNonZeroNode=head;
        for (integerNode* cur = head; cur; cur = cur->next) {
            if(cur->coefficient!=0) lastNonZeroNode=cur;
        }
        if(!lastNonZeroNode->next) return; // its last 

        integerNode* tmp=lastNonZeroNode->next;
        lastNonZeroNode->next=nullptr;
        while(tmp){
            integerNode* toDelete = tmp;
            tmp=tmp->next;
            delete toDelete;
        }
    }

   public:  // friend
    friend std::istream& operator>>(std::istream& is, POLYNOMIAL& c);
    friend std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c);
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
    c.CheckForReduce();
    return is;
}