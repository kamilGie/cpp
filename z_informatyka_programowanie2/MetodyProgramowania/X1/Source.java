//kamil gieras - nr grupy a 
import java.util.Scanner;

class Source {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int z = scanner.nextInt();
        while (z-- > 0) {
            int zestawNumer = scanner.nextInt();
            scanner.next();
            int liczbaWierszy = scanner.nextInt();
            int liczbaKolumn = scanner.nextInt();   
            int [][]tablica = new int[liczbaWierszy][liczbaKolumn];
            for(int i = 0 ; i < liczbaKolumn* liczbaWierszy ; i++) {
                tablica[i/liczbaKolumn][i%liczbaKolumn] = scanner.nextInt();
            }
            int startWiersza=0,koniecWiersza=0;
            int startKolumny=0,koniecKolumny=0;
            int msum=0;
            // todo 

            System.out.println(zestawNumer + ": ms_tab = a["+startWiersza+".."+koniecWiersza+ "]["+"["+startKolumny+".."+koniecKolumny+"], msum="+msum);
        }
    }
}