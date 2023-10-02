def part1(player1: str, player2: str) -> int:
    totalPoints: int = 0
    for p1, p2 in zip(player1, player2):
        if p1 == 'A':
            if p2 == 'X': totalPoints += 4
            if p2 == 'Y': totalPoints += 8
            if p2 == 'Z': totalPoints += 3
        elif p1 == 'B':
            if p2 == 'X': totalPoints += 1
            if p2 == 'Y': totalPoints += 5
            if p2 == 'Z': totalPoints += 9
        elif p1 == 'C':
            if p2 == 'X': totalPoints += 7
            if p2 == 'Y': totalPoints += 2
            if p2 == 'Z': totalPoints += 6
    return totalPoints




def part2(player1: str, player2: str) -> int:
    totalPoints: int = 0
    for (p1, p2) in zip(player1, player2):
        if p1 == 'A':
            if p2 == 'X': totalPoints += 3
            if p2 == 'Y': totalPoints += 4
            if p2 == 'Z': totalPoints += 8
        elif p1 == 'B':
            if p2 == 'X': totalPoints += 1
            if p2 == 'Y': totalPoints += 5
            if p2 == 'Z': totalPoints += 9
        elif p1 == 'C':
            if p2 == 'X': totalPoints += 2
            if p2 == 'Y': totalPoints += 6
            if p2 == 'Z': totalPoints += 7

    return totalPoints


if __name__ == "__main__":
    p1: str = ''
    p2: str = ''
    with open("./puzzle_input.txt", "r") as input_file:
        for line in input_file.readlines():
            p1 += line[0]
            p2 += line[2]
    
    print("Part 1:", part1(p1, p2))
    print("Part 2:", part2(p1, p2))
