package algo;

import java.util.*;
import java.io.*;

public class BOJ2624 {

	static int T;
	static int k;
	static int[] coins = new int[11];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		
		for (int i=0;i<k;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int cost = Integer.parseInt(st.nextToken());
			int nums = Integer.parseInt(st.nextToken());
			coins[cost] = nums;
		}
		
		
	}
}
