package algo;

import java.util.*;
import java.io.*;

public class BOJ2156_2 {
	
	static int n;
	static int[] wines;
	static int[][] drink;
	static int[] nowMax;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		wines = new int[n];
		drink = new int[n][2];
		nowMax = new int[n];
		int answer = 0;
		
		for (int i=0;i<n;i++) {
			wines[i] = Integer.parseInt(br.readLine());
		}
		
		if (n == 1) {
			System.out.println(wines[0]);
		} else if (n == 2) {
			System.out.println(wines[0] + wines[1]);
		} else {
			drink[0][0] = wines[0];
			drink[0][1] = wines[0];
			drink[1][0] = wines[1];
			drink[1][1] = wines[0] + wines[1];
			
			nowMax[0] = drink[0][0];
			nowMax[1] = drink[1][1];
			answer = nowMax[1];
			for (int i=2;i<n;i++) {
				drink[i][0] = nowMax[i-2] + wines[i];
				drink[i][1] = drink[i-1][0] + wines[i];
				nowMax[i] = Math.max(nowMax[i-1], Math.max(drink[i][0], drink[i][1]));
				answer = Math.max(answer, Math.max(drink[i][0], drink[i][1]));
			}
			
			System.out.println(answer);
		}
	}
}
