def part1(candies):
    maxi, suma = 0, 0
    for index, candy in enumerate(candies):
        if candy == -1 or index == len(candies) - 1:
            maxi = max(maxi, suma)
            suma = 0
        else:
            suma += candy
    return maxi

def insert_to_heap(heap, candy):
    for i in range(len(heap)):
        if candy > heap[i]:
            saved = heap[i]
            heap[i] = candy
            if i == len(heap) - 1:
                return heap
            for j in range(i + 1, len(heap) - 1):
                tempSaved = heap[j]
                heap[j] = saved
                saved = tempSaved

            heap[len(heap) - 1] = saved
            return heap
    return heap


def part2(candies):
    heap = [0, 0, 0]
    suma = 0

    for index, candy in enumerate(candies):
        if candy == -1 or index == len(candies) - 1:
            if not suma and index == len(candies) - 1:
                suma = candy
            heap = insert_to_heap(heap, suma)
            suma = 0
        else:
            suma += candy

    return sum(heap)

if __name__ == "__main__":
    # Read and saves the file
    candies = []
    with open("./input_puzzle.txt", "r") as file:
        for line in file.readlines():
            processed_line = line.replace("\n", "")
            if processed_line:
                candies.append(int(processed_line))
            else:
                candies.append(-1)

    # Solve the both parts
    answer1 = part1(candies)
    print("The part 1 is:", answer1)
    answer2 = part2(candies)
    print("The part 2 is:", answer2)

