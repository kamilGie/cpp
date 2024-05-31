
//kamil gieras - nr grupy a 
import java.util.Scanner;

import javax.rmi.ssl.SslRMIClientSocketFactory;

class Source {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int z = scanner.nextInt();
        while (z-- > 0) {
            int zestawNumer = scanner.nextInt();
            scanner.next();
            int liczbaWierszy = scanner.nextInt();
            int liczbaKolumn = scanner.nextInt();
            int[][] tablica = new int[liczbaWierszy][liczbaKolumn];
            for (int i = 0; i < liczbaKolumn * liczbaWierszy; i++) {
                tablica[i / liczbaKolumn][i % liczbaKolumn] = scanner.nextInt();
            }
            int startWiersza = 0, koniecWiersza = 0;
            int startKolumny = 0, koniecKolumny = 0;
            int msum = -1;

            for (int i = 0; i < liczbaWierszy; i++) {
                int[] arr = new int[liczbaKolumn];
                for (int j = i; j < liczbaWierszy; j++) {
                    for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
                        arr[kolumna] += tablica[j][kolumna];
                    }
                    int kadnesRes = Integer.MIN_VALUE;
                    int suma = 0;
                    int kolumnaStart = 0;
                    int kolumnaKoniec = 0;
                    for (int k = 0; k < arr.length; k++) {
                        suma += arr[k] > 0 ? arr[k] * 3 : arr[k] * 2;
                        if (suma > kadnesRes) {
                            kadnesRes = suma;
                            kolumnaKoniec = k;
                        }
                        if (suma < 0) {
                            suma = 0;
                            kolumnaStart = k + 1;
                        }
                    }
                    if ((kadnesRes > msum) || (kadnesRes == msum && ((j - i) + (kolumnaKoniec - kolumnaStart) < ((koniecWiersza - startWiersza) + (koniecKolumny - startKolumny))))) {
                        msum = kadnesRes;
                        startWiersza = i;
                        koniecWiersza = j;
                        koniecKolumny = kolumnaKoniec;
                        startKolumny = kolumnaStart;
                    }
                }
            }
            System.out.print(zestawNumer + ": ms_tab ");
            if (msum < 0) {
                System.out.println("is empty");
            } else {
                System.out.println("= a[" + startWiersza + ".." + koniecWiersza + "][" + "[" + startKolumny + ".."
                        + koniecKolumny + "], msum=" + msum);
            }
        }
    }
}