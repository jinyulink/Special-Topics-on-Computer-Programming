	初始化-> n, sum=0, ans=INF, coin[200], bitset<20000> dp[20000]
	dp[0]=1 
	for(i: 0~n)	input <- coin[i], sum+=coin[i]
	for(k: 0~n)
		for(i: sum~0)
			for(j: sum~0)
				if(dp[i][j])
					dp[j+coin[i]]=dp[j+coin[i]]|dp[j]; 
                    dp[j]=dp[j]|dp[j]<<coin[i];
	for(i: 0~sum)
		for(j: 0~sum)
			if(dp[i][j])	ans=min(拿最多錢的人-拿最少錢的人)
