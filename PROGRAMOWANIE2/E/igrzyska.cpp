#include "igrzyska.hpp"

unsigned int PLAYER_CLASS::getRemainingHealth() {
    return static_cast<unsigned int>(float(health) / float(maxHealth) * 100.0f);
}
