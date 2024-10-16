#define RETURN_REMAINDER true
#define ALLOW_EQUALITY true
#define DENY_EQUALITY false


class POLYNOMIAL {
   public:
    struct integerNode {
        integerNode(int coefficient = 0) : coefficient(coefficient) {}
        integerNode(integerNode** insertNode, int coefficient = 0) : coefficient(coefficient) {
            next = *insertNode;  // Set next to the node pointed by insertNode
            *insertNode = this;  // Update insertNode to point here
        };
        integerNode* next = nullptr;
        int coefficient;
    };
    integerNode* head = nullptr;
    static int overloaded;


   public:
    POLYNOMIAL(){};

    POLYNOMIAL(const POLYNOMIAL& toClone) {
        integerNode* prev = nullptr;
        for (integerNode* other = toClone.head; other; other = other->next) {
            integerNode* newNode = new integerNode(other->coefficient);
            prev ? prev->next = newNode : head = newNode;  // its first ?
            prev = newNode;
        }
        CheckForReduce();
    };

    POLYNOMIAL(int degree, ...) {
        va_list args;
        va_start(args, degree);
        integerNode* prev = nullptr;
        for (int i = 0; i <= degree; i++) {
            integerNode* newNode = new integerNode(va_arg(args, int));
            prev ? prev->next = newNode : head = newNode;  // its first ?
            prev = newNode;
        }
        va_end(args);
        CheckForReduce();
    }

    ~POLYNOMIAL() { clear(); }


   public:
    POLYNOMIAL operator=(const POLYNOMIAL& copy) {
        clear();
        new integerNode(&head, 0);  // making polynomial empty (0,0) to add the copy and make it same
        return *this += copy;
    }

    POLYNOMIAL operator/(const POLYNOMIAL& right) { return division(*this, right); }
    POLYNOMIAL operator/=(const POLYNOMIAL& right) { return *this = division(*this, right); }
    POLYNOMIAL operator%(const POLYNOMIAL& right) { return division(*this, right, RETURN_REMAINDER); }
    POLYNOMIAL operator%=(const POLYNOMIAL& right) { return *this = division(*this, right, RETURN_REMAINDER); }

    POLYNOMIAL operator>>(int amount) { return *this >>= amount; }
    POLYNOMIAL operator>>=(int amount) {
        while (amount--) {
            new integerNode(&head);
        }
        return *this;
    }

    POLYNOMIAL operator<<(int amount) { return POLYNOMIAL(*this) <<= amount; }
    POLYNOMIAL operator<<=(int amount) {
        while (amount-- && head) {
            integerNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator-(const POLYNOMIAL& other) { return POLYNOMIAL(*this) -= other; }
    POLYNOMIAL operator-=(const POLYNOMIAL& other) {
        POLYNOMIAL opposite(other);
        opposite.multiply(-1);
        return *this+=opposite;
    }

    POLYNOMIAL operator+(const POLYNOMIAL& other) { return POLYNOMIAL(*this) += other; }
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
            new integerNode(&mineCurrent->next, otherCurrent->coefficient);
            mineCurrent = mineCurrent->next;
            otherCurrent = otherCurrent->next;
        }
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator*(const POLYNOMIAL& other) { return POLYNOMIAL(*this) *= other; }
    POLYNOMIAL operator*=(const POLYNOMIAL& other) {
        integerNode* otherCurrent = other.head;

        int multiplicationDegree = 0;
        POLYNOMIAL res(0, 0), partialProduct;
        while (otherCurrent) {
            partialProduct = *this;
            partialProduct.multiply(otherCurrent->coefficient);
            for (int i = 0; i < multiplicationDegree; i++) {
                new integerNode(&partialProduct.head);
            }
            multiplicationDegree++;
            res += partialProduct;
            otherCurrent = otherCurrent->next;
        }
        return *this = res;
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

    void* operator new(size_t size) {
        overloaded++;
        return ::operator new(size);
    }
    void operator delete(void* ptr) {
        overloaded--;
        ::operator delete(ptr);
    }



   private: //private methods
    void clear() {
        while (head) {
            integerNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }


    void CheckForReduce() {
        if (!head) return;  // there is no numbers
        removeLeadingZeros();
        int minValue = minimalNonZeroCoefficient();
        for (int reducer = minValue; reducer > 1; reducer--) {
            if (minValue % reducer != 0) continue;
            bool toReduce = true;
            for (integerNode* cur = head; cur && toReduce; cur = cur->next) {
                if (cur->coefficient % reducer != 0) toReduce = false;
            }
            if (toReduce) {
                for (integerNode* cur = head; cur; cur = cur->next) {
                    cur->coefficient /= reducer;
                }
                minValue /= reducer;
                reducer = minValue + 1;
            }
        }
    }

    void removeLeadingZeros() {
        integerNode* lastNonZeroNode = head;
        for (integerNode* cur = head; cur; cur = cur->next) {
            if (cur->coefficient) lastNonZeroNode = cur;
        }
        if (!lastNonZeroNode->next) return;  // last is non zero node

        integerNode* tmp = lastNonZeroNode->next;
        lastNonZeroNode->next = nullptr;
        while (tmp) {
            integerNode* toDelete = tmp;
            tmp = tmp->next;
            delete toDelete;
        }
    }

    int minimalNonZeroCoefficient() {
        int minValue = INT_MAX;
        for (integerNode* cur = head; cur; cur = cur->next) {
            if (cur->coefficient != 0 && minValue > abs(cur->coefficient)) minValue = abs(cur->coefficient);
        }
        return minValue;
    }


    POLYNOMIAL division(POLYNOMIAL quotientBar, const POLYNOMIAL& divisor, bool returnRemainder = false) {
        POLYNOMIAL res;
        while (divisor.getDegree() <= quotientBar.getDegree()) {
            bool fraction = quotientBar.getLeadingCoefficient() % divisor.getLeadingCoefficient();
            if (fraction) {
                int multiplier = abs(divisor.getLeadingCoefficient());
                res.multiply(multiplier);
                quotientBar.multiply(multiplier);
            }

            int NumberAboveBar = quotientBar.getLeadingCoefficient() / divisor.getLeadingCoefficient();
            if (!returnRemainder) new integerNode(&res.head, NumberAboveBar);

            quotientBar.subtractPartialProduct(&divisor, NumberAboveBar);
        }
        if (returnRemainder) res = quotientBar;
        res.CheckForReduce();
        return res;
    }

    int getDegree() const {
        int Degree = -1;
        for (integerNode* cur = head; cur; cur = cur->next) {
            Degree++;
        }
        return Degree;
    }

    int getLeadingCoefficient() const {
        integerNode* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        return cur->coefficient;
    }

    void multiply(int multiplier) {
        for (integerNode* cur = head; cur; cur = cur->next) {
            cur->coefficient *= multiplier;
        }
    }

    void subtractPartialProduct(const POLYNOMIAL* divisor, int NumberAboveBar) {
        integerNode* currentNode_qb = moveToRelativeDegree(getDegree() - divisor->getDegree());
        integerNode* currentNode_divisor = divisor->head;
        while (true) {
            currentNode_qb->coefficient -= (currentNode_divisor->coefficient * NumberAboveBar);

            if (!currentNode_qb->next->next) break;  // if next node is last its always resetting number so we brake to delete it
            currentNode_divisor = currentNode_divisor->next;
            currentNode_qb = currentNode_qb->next;
        }
        delete currentNode_qb->next;
        currentNode_qb->next = nullptr;
    }

    integerNode* moveToRelativeDegree(int degreeDif) {
        integerNode* res = head;
        while (degreeDif--) {
            res = res->next;
        }
        return res;
    }



   public:
    friend std::istream& operator>>(std::istream& is, POLYNOMIAL& c);
};
int POLYNOMIAL::overloaded = 0;



bool compare(const POLYNOMIAL& smaller, const POLYNOMIAL& bigger, bool allowEquality) {
    bool res = allowEquality;
    POLYNOMIAL::integerNode* biggerNode = bigger.head;
    POLYNOMIAL::integerNode* smallerNode = smaller.head;
    while (biggerNode && smallerNode) {
        if (biggerNode->coefficient != smallerNode->coefficient) res = biggerNode->coefficient > smallerNode->coefficient;
        biggerNode = biggerNode->next;
        smallerNode = smallerNode->next;
    }
    if (smallerNode) return false;
    if (biggerNode) return true;
    return res;
}
bool operator<(const POLYNOMIAL& smaller, const POLYNOMIAL& bigger) { return compare(smaller, bigger, DENY_EQUALITY); }
bool operator<=(const POLYNOMIAL& smaller, const POLYNOMIAL& bigger) { return compare(smaller, bigger, ALLOW_EQUALITY); }
bool operator>(const POLYNOMIAL& bigger, const POLYNOMIAL& smaller) { return compare(smaller, bigger, DENY_EQUALITY); }
bool operator>=(const POLYNOMIAL& bigger, const POLYNOMIAL& smaller) { return compare(smaller, bigger, ALLOW_EQUALITY); }
bool operator==(const POLYNOMIAL& pol1, const POLYNOMIAL& pol2) { return compare(pol1, pol2, ALLOW_EQUALITY) && compare(pol2, pol1, ALLOW_EQUALITY); }
bool operator!=(const POLYNOMIAL& pol1, const POLYNOMIAL& pol2) { return compare(pol1, pol2, DENY_EQUALITY) || compare(pol2, pol1, DENY_EQUALITY); }



std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c) {
    os << "( ";
    for (POLYNOMIAL::integerNode* cur = c.head; cur; cur = cur->next) {
        os << cur->coefficient;
        os << (cur->next ? ", " : " )");  // its last ?
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
        prev ? prev->next = cur : c.head = cur;  // its not first ?
        prev = cur;
    }
    c.CheckForReduce();
    return is;
}
