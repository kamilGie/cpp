#include <gtest/gtest.h>
#include "igrzyska.hpp"

using namespace testing::internal;

TEST(squad_class, squadGeters) {
    SQUAD_CLASS squad("1");
    BERSERKER_CLASS berserker("2","3");
    HUMAN_CLASS human("4");
    BEAST_CLASS beast("5");
    squad.addPleyer(&berserker);
    squad.addPleyer(&human);
    squad.addPleyer(&beast);
    ASSERT_EQ(squad.getAgility(),5);
    ASSERT_EQ(squad.getDamage(),105);
    ASSERT_EQ(squad.getRemainingHealth(),100);
}

TEST(squad_class, getDmg) {
    SQUAD_CLASS squad("1");
    BERSERKER_CLASS berserker("2","3");
    HUMAN_CLASS human("4");
    BEAST_CLASS beast("5");
    squad.addPleyer(&berserker);
    squad.addPleyer(&human);
    squad.addPleyer(&beast);

    //squad.takeDamage(100);
    //ASSERT_EQ(squad.getRemainingHealth(),93);
}

TEST(squad_class, printParams) {
    SQUAD_CLASS squad("1");

    CaptureStdout();
    squad.printParams();
    EXPECT_EQ(GetCapturedStdout(),"1:nemo\n");


    BERSERKER_CLASS berserker("2","3");
    HUMAN_CLASS human("4");
    BEAST_CLASS beast("5");
    squad.addPleyer(&berserker);
    squad.addPleyer(&human);
    squad.addPleyer(&beast);

    CaptureStdout();
    squad.printParams();
    EXPECT_EQ(GetCapturedStdout(),"1:3:100:105:5:\n2:200:200:100%:35:5:15\n4:200:200:100%:30:10:10\n5:150:150:100%:40:20:\n");

}