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
		wines = new int[n]; // 포도주 양
		// drink[n][0] = 현재 인덱스의 포도주를 마시고, 1번 연속으로 마신 상태
		// drink[n][1] = 현재 인덱스의 포도주를 마시고, 2번 연속으로 마신 상태
		drink = new int[n][2]; 
		nowMax = new int[n]; // 0번부터 n번째 인덱스 까지의 값중 최댓값을 저장.
		int answer = 0;
		
		for (int i=0;i<n;i++) {
			wines[i] = Integer.parseInt(br.readLine());
		}
		
		// n이 3보다 작으면 그냥 계산
		if (n == 1) {
			System.out.println(wines[0]);
		} else if (n == 2) {
			System.out.println(wines[0] + wines[1]);
		} else { // n이 3이상이면
			// drink[n][m] = n번째 포도주를 마실 때, m+1번 연속으로 마심.
			drink[0][0] = wines[0];
			drink[0][1] = wines[0];
			drink[1][0] = wines[1];
			drink[1][1] = wines[0] + wines[1];
			
			nowMax[0] = drink[0][0]; // nowMax[0]은 0번째 포도주까지 진행했을 때의 최댓값.
			nowMax[1] = drink[1][1]; // nowMax[1]은 1번째 포도주까지 진행했을 때의 최댓값.
			answer = nowMax[1];
			for (int i=2;i<n;i++) {
				// i-2번째 값들 중 최댓값만 더하면 됨.
				drink[i][0] = nowMax[i-2] + wines[i];
				drink[i][1] = drink[i-1][0] + wines[i];
				
				// 현재 인덱스의 최댓값은 i-1번까지의 최댓값과 현재 drink값 중 더 큰 값
				nowMax[i] = Math.max(nowMax[i-1], Math.max(drink[i][0], drink[i][1]));
				answer = Math.max(answer, Math.max(drink[i][0], drink[i][1]));
			}
			
			System.out.println(answer);
		}
	}
}
