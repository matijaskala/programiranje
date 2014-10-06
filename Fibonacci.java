import java.util.Scanner;
import java.util.Vector;

public class Fibonacci {
	private static Vector<Long> shranjeneVrednosti;

	public static long izracunaj(int i) {
		if ( shranjeneVrednosti == null ) {
			shranjeneVrednosti = new Vector<Long>();
			shranjeneVrednosti.add(0l);
			shranjeneVrednosti.add(1l);
		}
		if ( shranjeneVrednosti.size() > i )
			return shranjeneVrednosti.elementAt(i);
		long rezultat = izracunaj(i-1) + izracunaj(i-2);
		shranjeneVrednosti.add(rezultat);
		return rezultat;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int i = scanner.nextInt();
		long stevilo = Fibonacci.izracunaj(i);
		System.out.println(stevilo);
	}
}
