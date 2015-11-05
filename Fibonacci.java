
public class Fibonacci {

	public static void main(String[] args) {
		System.out.println(fibRec(11));
		System.out.println(fibDyn(1001));
		System.out.println(fibIt(1001));
		System.out.println(Long.MAX_VALUE); // To show how big the numbers are
	}
	
	// Recursive
	static long fibRec(int n) {
		if (n < 2) return n;
		
		return fibRec(n - 2) + fibRec(n - 1);
	}
	
	// Dynamic
	static long fibDyn(int n) {
		long[] mem = new long[n + 1];
		
		return fibMem(n, mem);
	}
	
	static long fibMem(int n, long[] mem) {
		if (n < 2) return n;
		
		if (mem[n] != 0) return mem[n];
		
		mem[n] = fibMem(n - 2, mem) + fibMem(n - 1, mem);
		
		return mem[n];
		
	}
	
	// Iterative
	static long fibIt(int n) {
		long varA = 0;
		long varB = 1;
		int i;
		for (i = 0; i < n; i++) {
			if (i % 2 == 0) {
				varA += varB;
			} else {
				varB += varA;
			}
		}
		return (i % 2 == 0) ? varA : varB;
	}

}
