package algo;

import java.util.*;
import java.io.*;

public class BOJ16987 {
	
	static int N;
	static int[][] eggInfo;
	static int answer = 0;
	
	static void findMaxBreakable(int index, int breakCount) {
		// 끝까지 왔거나 안 깨진 계란이 1개만 남으면 종료
		if (index >= N || breakCount >= N-1) {
			answer = Math.max(answer, breakCount);
			return;
		}
		
		int nowS = eggInfo[index][0];
		int nowW = eggInfo[index][1];
		if (nowS <= 0) {
			findMaxBreakable(index+1, breakCount);
		} else {
			for (int i=0;i<N;i++) {
				// 자기 자신과 깰 수는 없음.
				if (i == index) {
					continue;
				}
				
				int nextS = eggInfo[i][0];
				int nextW = eggInfo[i][1];
				// 깨진 계란 패스
				if (nextS <= 0) {
					continue;
				}
				eggInfo[index][0] -= nextW;
				eggInfo[i][0] -= nowW;
				
				// 둘 다 깨짐
				if (eggInfo[index][0] <= 0 && eggInfo[i][0] <= 0) {
					findMaxBreakable(index+1, breakCount+2);
				}
				// 둘 중 하나만 깨짐
				else if (eggInfo[index][0] <= 0 || eggInfo[i][0] <= 0) {
					findMaxBreakable(index+1, breakCount+1);
				}
				// 둘 다 안깨짐
				else if (eggInfo[index][0] > 0 && eggInfo[i][0] > 0) {
					findMaxBreakable(index+1, breakCount);
				}
				
				eggInfo[index][0] += nextW;
				eggInfo[i][0] += nowW;
			}			
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		eggInfo = new int[N][2]; // [][0] = 내구도, [][1] = 무게
		for (int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			eggInfo[i][0] = s;
			eggInfo[i][1] = w;
		}
		
		// 1. i번 계란과 다른 모든 계란 부딪혀보기
		// 2. 1 과정 후 i+1 계란으로 다른 모든 계란 부딪혀보기
		// 3. 반복
		
		findMaxBreakable(0, 0);
		
		System.out.println(answer);
	}
}
