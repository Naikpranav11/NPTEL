def play_game(t, test_cases):
    results = []
    
    for i in range(t):
        n, m = test_cases[i][0]
        yudhisthira_asthras = test_cases[i][1][0]
        duryodhana_asthras = test_cases[i][1][1]
        yudhisthira_count = n
        duryodhana_count = m
        
        while yudhisthira_count > 0 and duryodhana_count > 0:
            if len(yudhisthira_asthras) == 0 or len(duryodhana_asthras) == 0:
                break
            
            yudhisthira_chosen = yudhisthira_asthras.pop(0)
            duryodhana_chosen = duryodhana_asthras.pop(0)
            
            if yudhisthira_chosen > duryodhana_chosen:
                duryodhana_count -= 1
            elif yudhisthira_chosen < duryodhana_chosen:
                yudhisthira_count -= 1
        
        if yudhisthira_count > 0 and duryodhana_count == 0:
            results.append("Yudhisthira")
        elif yudhisthira_count == 0 and duryodhana_count > 0:
            results.append("Duryodhana")
        else:
            results.append("Draw")
    
    return results

t = int(input())
test_cases = []

for _ in range(t):
    n, m = map(int, input().split())
    yudhisthira_asthras = list(map(int, input().split()))
    duryodhana_asthras = list(map(int, input().split()))
    test_cases.append(((n, m), (yudhisthira_asthras, duryodhana_asthras)))

results = play_game(t, test_cases)

for result in results:
    print(result)
