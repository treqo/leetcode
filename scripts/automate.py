import leetcode
import datetime

def get_solved_today():
    today = datetime.date.today()
    user = leetcode.User()
    solved_problems = user.solved_problems()
    
    # Filter problems solved today
    today_solved = []
    for problem in solved_problems:
        solved_date = datetime.datetime.strptime(problem['solved_date'], "%Y-%m-%d")
        if solved_date.date() == today:
            today_solved.append(problem)
    
    return today_solved

solved_today = get_solved_today()
print(solved_today)
