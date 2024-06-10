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

    ~POLYNOMIAL() {
        clear();
    }

   public:
    POLYNOMIAL operator=(const POLYNOMIAL& copy) {
        clear();
        new integerNode(&head, 0);  // making polynomial empty (0,0) to add the copy and make it same
        *this += copy;
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
            new integerNode(&mineCurrent->next, otherCurrent->coefficient);
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
            new integerNode(&mineCurrent->next, otherCurrent->coefficient * -1);
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
                new integerNode(&partialProduct.head);
            }
            multiplicationDegree++;
            res += partialProduct;
            otherCurrent = otherCurrent->next;
        }
        *this = res;
        return *this;
    }

    POLYNOMIAL operator/(const POLYNOMIAL& other) {
        POLYNOMIAL res = *this;
        res /= other;
        return res;
    }

    POLYNOMIAL operator/=(const POLYNOMIAL& right) {
        POLYNOMIAL * left = this;

        //wyliczam liczbe z najwieksza potega z prawego
        int right_NumberWithTheBigest_xPow=0;
        int right_XPow=-1;
        for (integerNode* cur = right.head; cur; cur = cur->next) {
            right_NumberWithTheBigest_xPow=cur->coefficient;
            right_XPow++;
        }
        integerNode* res = new integerNode; // tworze lanuch ktory bedzie wynikiem z dzielenia 
        while(true){ 
            //wybieram  liczbe z nwjieksza potega z lewego wielomianu
            int left_NumberWithTheBigest_xPow=0;
            int left_XPow=-1;
            for (integerNode* cur = head; cur; cur = cur->next) {
                left_NumberWithTheBigest_xPow=cur->coefficient;
                left_XPow++;
            }
            // jesli prawy wielomian ma wieksza potege, dzielenie sie konczy
            if(right_XPow>left_XPow) break; 

            // jesli liczby przy najwiekszych potegach podzielone  (lewy/prawy) najwieksze nie sa cala to mnoze  res oraz oraz lewy wielomian razy liczba prawy przy najwiekszej potedze oraz sama najwieksza lewa liczba
            if(left_NumberWithTheBigest_xPow%right_NumberWithTheBigest_xPow){
                for (integerNode* cur = res; cur; cur = cur->next) {
                    cur->coefficient*=abs(right_NumberWithTheBigest_xPow);
                }   
                for (integerNode* cur = left->head; cur; cur = cur->next) {
                    cur->coefficient*=abs(right_NumberWithTheBigest_xPow);
                } 
                left_NumberWithTheBigest_xPow*=abs(right_NumberWithTheBigest_xPow);
            }

            // tworze zmienna int  NumberAboveTheColumn ktora bedzie  dzieleniem liczb  z najwiekszego lewego wielomiany przez prawy najwieksza oraz zmienna wspolycznik jej  x dla tej liczby rowny (lewy - prawy potegi x)
            int NumberAboveTheColumn = left_NumberWithTheBigest_xPow/right_NumberWithTheBigest_xPow;
            int NumberAboveTheColumn_XPow = left_XPow-right_XPow;
            // NumberAboveTheColumn dodaje do res 
            new integerNode(&res->next,NumberAboveTheColumn);
            // NumberAboveTheColumn mnoze razy other i odejmuje od lewego wielomianu 
            integerNode* leftPrev=nullptr;
            integerNode* leftCurrent = head;
            integerNode* rightCurrent = right.head;
            for ( int i = 0 ; i<NumberAboveTheColumn_XPow;i++){
                leftCurrent=leftCurrent->next;
                leftPrev=leftCurrent;
            }
            while(leftCurrent->next && rightCurrent->next){
                leftCurrent->coefficient=leftCurrent->coefficient-(rightCurrent->coefficient*NumberAboveTheColumn);
                rightCurrent=rightCurrent->next;
                leftPrev=leftCurrent;
                leftCurrent=leftCurrent->next;
            }
            leftPrev->next=nullptr;
            delete leftCurrent;
        }
        //ten wielomian  rowna sie res 
        clear();
        head = res->next;
        delete res;
        CheckForReduce();
        return *this;
    }

    POLYNOMIAL operator%(const POLYNOMIAL& other) {
        POLYNOMIAL res = *this;
        res %= other;
        return res;
    }

    POLYNOMIAL operator%=(const POLYNOMIAL& right) {
        POLYNOMIAL * left = this;
        //wyliczam liczbe z najwieksza potega z prawego
        int right_NumberWithTheBigest_xPow=0;
        int right_XPow=-1;
        for (integerNode* cur = right.head; cur; cur = cur->next) {
            right_NumberWithTheBigest_xPow=cur->coefficient;
            right_XPow++;
        }

        // while dopoki ten wielomian ma wieksza potege lub rowna niz other ma najwieksza ta potege 
        while(true){
            //wybieram  liczbe z nwjieksza potega z lewego wielomianu
            int left_NumberWithTheBigest_xPow=0;
            int left_XPow=-1;
            for (integerNode* cur = head; cur; cur = cur->next) {
                left_NumberWithTheBigest_xPow=cur->coefficient;
                left_XPow++;
            }
            if(right_XPow>left_XPow) break;
            // jesli liczby przy najwiekszych potegach podzielone  (lewy/prawy) najwieksze nie sa cala to mnoze  res oraz oraz lewy wielomian razy liczba prawy przy najwiekszej potedze oraz sama najwieksza lewa liczba
            if(left_NumberWithTheBigest_xPow%right_NumberWithTheBigest_xPow){ 
                for (integerNode* cur = left->head; cur; cur = cur->next) {
                    cur->coefficient*=abs(right_NumberWithTheBigest_xPow);
                } 
                left_NumberWithTheBigest_xPow*=abs(right_NumberWithTheBigest_xPow);
            }

            // tworze zmienna int  NumberAboveTheColumn ktora bedzie  dzieleniem liczb  z najwiekszego lewego wielomiany przez prawy najwieksza oraz zmienna wspolycznik jej  x dla tej liczby rowny (lewy - prawy potegi x)
            int NumberAboveTheColumn = left_NumberWithTheBigest_xPow/right_NumberWithTheBigest_xPow;
            int NumberAboveTheColumn_XPow = left_XPow-right_XPow;
            // NumberAboveTheColumn mnoze razy other i odejmuje od lewego wielomianu 
            integerNode* leftPrev=nullptr;
            integerNode* leftCurrent = head;
            integerNode* rightCurrent = right.head;
            for ( int i = 0 ; i<NumberAboveTheColumn_XPow;i++){
                leftCurrent=leftCurrent->next;
                leftPrev=leftCurrent;
            }
            while(leftCurrent->next && rightCurrent->next){
                leftCurrent->coefficient=leftCurrent->coefficient-(rightCurrent->coefficient*NumberAboveTheColumn);
                rightCurrent=rightCurrent->next;
                leftPrev=leftCurrent;
                leftCurrent=leftCurrent->next;
            }
            leftPrev->next=nullptr;
            delete leftCurrent;
        }
        //ten wielomian  rowna sie res 
        CheckForReduce();
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
            new integerNode(&head);
        }
        return *this;
    }

    POLYNOMIAL operator<<=(int amount) {
        while (amount-- && head) {
            integerNode* tmp = head;
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

    void* operator new(size_t size) {
        overloaded++;
        return ::operator new(size);
    }

    void operator delete(void* ptr) {
        overloaded--;
        ::operator delete(ptr);
    }

   private:  // private methods
    void clear() {
        while (head) {
            integerNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void CheckForReduce() {
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

   public:
    friend std::istream& operator>>(std::istream& is, POLYNOMIAL& c);
};

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

bool operator<(const POLYNOMIAL& smaller, const POLYNOMIAL& bigger) {
    return compare(smaller, bigger, false);
}

bool operator<=(const POLYNOMIAL& smaller, const POLYNOMIAL& bigger) {
    return compare(smaller, bigger, true);
}

bool operator>(const POLYNOMIAL& bigger, const POLYNOMIAL& smaller) {
    return compare(smaller, bigger, false);
}

bool operator>=(const POLYNOMIAL& bigger, const POLYNOMIAL& smaller) {
    return compare(smaller, bigger, true);
}

bool operator==(const POLYNOMIAL& pol1, const POLYNOMIAL& pol2) {
    return compare(pol1, pol2, true) && compare(pol2, pol1, true);
}

bool operator!=(const POLYNOMIAL& pol1, const POLYNOMIAL& pol2) {
    return compare(pol1, pol2, false) || compare(pol2, pol1, false);
}

int POLYNOMIAL::overloaded = 0;