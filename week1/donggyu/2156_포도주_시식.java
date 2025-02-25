package algo;

import java.io.*;
import java.util.*;

public class BOJ_2156 {

//	포도주 잔 개수
    static int bottles;
//  포도주 양
    static Integer[] amounts;
//  dp 테이블
    static Integer[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        bottles = Integer.parseInt(bf.readLine());

        amounts = new Integer[bottles+1];

        for(int i = 1; i < bottles+1; i++) {
            amounts[i] = Integer.parseInt(bf.readLine());
        }

        dp = new Integer[bottles+1];
        
        dp[0] = 0;
        dp[1] = amounts[1];
//      포도주 잔 개수가 1개 이하일 경우 
        if(bottles>1)
            dp[2] = amounts[1]+amounts[2];
        
//      연속으로 3잔을 연속해서 먹을 수 없기 때문에 i번째 포도주 잔의 최댓값
//      = Max(i-2번째까지의 최대값+i번째 포도주 용량 /i-1번째까지의 최대값(i번째 채택X) / i-3번째까지의 최대값+i-1번째 포도주 용량+i번째 포도주 용량)
        for(int i = 3; i < dp.length; i++) {
            dp[i] = Math.max(Math.max(dp[i-2]+amounts[i], dp[i-1]), dp[i-3]+amounts[i-1]+amounts[i]);
        }
        System.out.println(dp[bottles]);
    }

}
