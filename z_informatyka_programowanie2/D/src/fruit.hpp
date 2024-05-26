// kamil gieras
#pragma once

class FRUIT_CLASS {
   public:
    unsigned int getWeights();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();

   private:
    unsigned int fruitWeight = 0;
};