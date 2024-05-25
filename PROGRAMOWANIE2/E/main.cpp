//Kamil Gieras
#include "igrzyska.hpp"

int main() {
    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);
    BERSERKER_CLASS human1("HUMAN1", "BEAST1");
    BERSERKER_CLASS human2 ( "HUMAN2", "BEAST2");
    BERSERKER_CLASS human3("HUMAN3", "BEAST3");
    BERSERKER_CLASS human4 ( "HUMAN4", "BEAST4");
    BERSERKER_CLASS human5 ( "HUMAN5", "BEAST5");
    BERSERKER_CLASS human6 ( "HUMAN6", "BEAST6");
    BERSERKER_CLASS human7 ( "HUMAN7", "BEAST7");
    BERSERKER_CLASS human8 ( "HUMAN8", "BEAST8");

    BERSERKER_CLASS beast1 ( "human1", "beast1");
    BERSERKER_CLASS beast2 ( "human2", "beast2");
    BERSERKER_CLASS beast3 ( "human3", "beast3");
    BERSERKER_CLASS beast4 ( "human4", "beast4");
    BERSERKER_CLASS beast5 ( "human5", "beast5");
    BERSERKER_CLASS beast6 ( "human6", "beast6");
    BERSERKER_CLASS beast7 ( "human7", "beast7");
    BERSERKER_CLASS beast8 ( "human8", "beast8");

    HUMAN_CLASS h1 ( "h1" );
    HUMAN_CLASS h2 ( "h2" );
    HUMAN_CLASS h3 ( "h3" );
    HUMAN_CLASS h4 ( "h4" );

    BEAST_CLASS b1 ( "b1" );
    BEAST_CLASS b2 ( "b2" );
    BEAST_CLASS b3 ( "b3" );
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

    std::cout << std::endl << std::endl;

    arena.fight( &squad1, &squad2 );

    std::cout << std::endl << std::endl;

    arena.fight( &squad1, &beast1 );
    return 0;
}