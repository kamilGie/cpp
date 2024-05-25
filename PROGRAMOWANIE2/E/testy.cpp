#include <gtest/gtest.h>
#include "igrzyska.hpp"

using namespace testing::internal;

TEST(squad_class, squadGeters) {
    SQUAD_CLASS squad("1");
    BERSERKER_CLASS berserker("2","3");
    HUMAN_CLASS human("4");
    BEAST_CLASS beast("5");
    squad.addPlayer(&berserker);
    squad.addPlayer(&human);
    squad.addPlayer(&beast);
    ASSERT_EQ(squad.getAgility(),5);
    ASSERT_EQ(squad.getDamage(),105);
    ASSERT_EQ(squad.getRemainingHealth(),100);
}

TEST(squad_class, getDmg) {
    SQUAD_CLASS squad("1");
    BERSERKER_CLASS berserker("2","3");
    HUMAN_CLASS human("4");
    BEAST_CLASS beast("5");
    squad.addPlayer(&berserker);
    squad.addPlayer(&human);
    squad.addPlayer(&beast);

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
    squad.addPlayer(&berserker);
    squad.addPlayer(&human);
    squad.addPlayer(&beast);

    //CaptureStdout();
    //squad.printParams();
    //EXPECT_EQ(GetCapturedStdout(),"1:3:100:105:5:\n2:200:200:100%:35:5:15\n4:200:200:100%:30:10:10\n5:150:150:100%:40:20:\n");

}

TEST(martynaTest, pleyerVsPlayer) {
    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);
    BERSERKER_CLASS human1("HUMAN1", "BEAST1");
    BERSERKER_CLASS beast4 ( "human4", "beast4");

    CaptureStdout();
    arena.fight(&beast4, &human1);
    EXPECT_EQ(GetCapturedStdout(),"human4:200:200:100%:35:5:15\nHUMAN1:200:200:100%:35:5:15\nHUMAN1:200:185:92%:35:5:15\nhuman4:200:185:92%:35:5:15\nHUMAN1:200:170:85%:35:5:15\nhuman4:200:170:85%:35:5:15\nHUMAN1:200:155:77%:35:5:15\nhuman4:200:155:77%:35:5:15\nHUMAN1:200:140:70%:35:5:15\nhuman4:200:140:70%:35:5:15\nHUMAN1:200:125:62%:35:5:15\nhuman4:200:125:62%:35:5:15\nHUMAN1:200:110:55%:35:5:15\nhuman4:200:110:55%:35:5:15\nHUMAN1:200:95:47%:35:5:15\nhuman4:200:95:47%:35:5:15\nHUMAN1:200:80:40%:35:5:15\nhuman4:200:80:40%:35:5:15\nHUMAN1:200:65:32%:35:5:15\nhuman4:200:65:32%:35:5:15\nHUMAN1:200:50:25%:35:5:15\nhuman4:200:50:25%:35:5:15\nBEAST1:200:35:17%:70:5\nhuman4:R.I.P.\nBEAST1:200:35:17%:70:5\nhuman4:R.I.P.\nHUMAN1:200:200:100%:37:7:15\n");
}


TEST(martynaTest, SquadVsSquad) {
    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);

    BERSERKER_CLASS human1("HUMAN1", "BEAST1");
    BERSERKER_CLASS human7 ( "HUMAN7", "BEAST7");

    BERSERKER_CLASS beast3 ( "human3", "beast3");
    BERSERKER_CLASS beast4 ( "human4", "beast4");
    BERSERKER_CLASS beast8 ( "human8", "beast8");
    HUMAN_CLASS h2 ( "h2" );
    BEAST_CLASS b4 ( "b4" );

    arena.fight(&beast4, &human1);

    SQUAD_CLASS squad1 ( "squad1" );
    squad1.addPlayer(&human7);
    squad1.addPlayer(&human1);
    squad1.addPlayer(&human7);

    SQUAD_CLASS squad2 ( "squad2" );
    squad2.addPlayer(&beast4);
    squad2.addPlayer(&b4);
    squad2.addPlayer(&beast3);
    squad2.addPlayer(&beast8);
    squad2.addPlayer(&h2);

    CaptureStdout();
    arena.fight( &squad1, &squad2 );
    EXPECT_EQ(GetCapturedStdout() , " squad1:2:100%:72:5\nHUMAN1:200:200:100%:37:7:15\nHUMAN7:200:200:100%:35:5:15\nsquad2:4:100%:140:5\nb4:150:150:100%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad2:4:100%:140:5\nb4:150:142:94%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad1:2:76%:72:5\nHUMAN1:200:152:76%:37:7:15\nHUMAN7:200:150:75%:35:5:15\nsquad2:4:100%:140:5\nb4:150:134:89%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad1:2:52%:72:5\nHUMAN1:200:104:52%:37:7:15\nHUMAN7:200:100:50%:35:5:15\nsquad2:4:100%:140:5\nb4:150:126:84%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad1:2:28%:72:5\nHUMAN1:200:56:28%:37:7:15\nHUMAN7:200:50:25%:35:5:15\nsquad2:4:100%:140:5\nb4:150:118:78%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad1:1:4%:74:7\nBEAST1:200:8:4%:74:7\nsquad1:1:4%:74:7\nBEAST1:200:8:4%:74:7\nsquad2:4:100%:140:5\nb4:150:118:78%:40:20\nh2:200:200:100%:30:10:10\nhuman3:200:200:100%:35:5:15\nhuman8:200:200:100%:35:5:15\nsquad1:1:100%:39:9\nHUMAN1:200:200:100%:39:9:15\nsquad2:4:100%:148:7\nb4:150:150:100%:42:22\nh2:200:200:100%:32:12:10\nhuman3:200:200:100%:37:7:15\nhuman8:200:200:100%:37:7:15\n" );
}