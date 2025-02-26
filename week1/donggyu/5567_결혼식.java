package algo;

import java.io.*;
import java.util.*;

public class BOJ_5567 {

	static int N, M;
	static ArrayList<ArrayList<Integer>> relations = new ArrayList<>();
	static boolean[] invited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		M = Integer.parseInt(bf.readLine());
		
		invited = new boolean[N+1];
		for(int i=0;i<N+1;i++) {
			relations.add(new ArrayList<Integer>());
		}
		
		for(int i=0;i<M;i++) {
			StringTokenizer st = new StringTokenizer(bf.readLine());
			int p1 = Integer.parseInt(st.nextToken());
			int p2 = Integer.parseInt(st.nextToken());
			relations.get(p1).add(p2);
			relations.get(p2).add(p1);
		}
		
		int ans = bfs(1);
		System.out.println(relations);
		System.out.println(ans);
		System.out.println(Arrays.toString(invited));

	}
	
	private static int bfs(int start) {
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(start);
		invited[start] = true;
		int depth = 0;
		int count = 0;
		
		while(!q.isEmpty()) {
			depth += 1;
			int now = q.poll();
			System.out.println("now: "+now+" relations.get(now): "+relations.get(now));
			
			for(int i=0;i<relations.get(now).size();i++) {
				if(invited[relations.get(now).get(i)]==true)
					continue;
				invited[relations.get(now).get(i)] = true;
				count++;
				q.add(relations.get(now).get(i));
			}
			System.out.println("q: "+ q);
			if(depth > 2)
				break;
		}
		return count;
	}
	
}
