<h1 align="center">
	💣 push swap
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 📘 프로젝트 소개

`push_swap` 프로젝트는 두 개의 스택을 사용하여 주어진 숫자들을 오름차순으로 정렬하는 프로그램을 작성하는 것을 목표로 합니다. 이 프로젝트에서는 스택 자료 구조를 활용해 데이터를 정렬하고, 이를 최소한의 명령어로 해결하는 것이 핵심입니다. 다른 여러 정렬 알고리즘들이 있지만 시간복잡도가 제일 낮은 **merge sort** 알고리즘을 적용하여 효율적인 정렬을 구현합니다.


## 💻 필수 구현 사항

- **스택 구조를 사용하여 숫자 정렬하기**:
  - 두 개의 스택(`a`와 `b`)을 사용해 주어진 정수를 오름차순으로 정렬합니다.
  - 스택 간의 데이터를 주고받는 명령어(`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)를 사용해 정렬을 완성합니다.
  

## ⚙️ 사용법

기본적인 `push_swap` 실행 방법:

```bash
./push_swap [숫자들]
```

예시:

```bash
$ ./push_swap 4 3 2 1
```

이 명령어는 `push_swap` 프로그램을 실행하여 주어진 숫자 배열을 정렬하는 데 필요한 명령어 목록을 출력합니다.


## 📂 주요 개념

### 1. **스택 (Stack)**

스택은 데이터를 한 방향으로 넣고 뺄 수 있는 선형 자료구조입니다. `push_swap`에서 스택은 후입선출(LIFO, Last In First Out) 방식으로 동작하며, 두 개의 스택(`a`, `b`)을 사용해 정렬을 구현합니다.


## 🧠 Merge Sort를 사용한 구현

### 1. **Merge Sort**란?

Merge Sort는 "분할 정복(Divide and Conquer)" 방식의 정렬 알고리즘입니다. 이 알고리즘은 입력 데이터를 절반씩 나누어 각각 정렬한 후, 두 개의 정렬된 리스트를 병합하여 하나의 정렬된 리스트를 얻는 방식으로 작동합니다.

**Merge Sort의 단계:**

1. **분할 (Divide)**: 리스트를 절반으로 나누어 더 이상 나눌 수 없을 때까지 분할합니다.
2. **정복 (Conquer)**: 각 분할된 리스트를 재귀적으로 정렬합니다.
3. **병합 (Combine)**: 분할된 리스트를 병합하여 정렬된 리스트로 만듭니다.

### 2. **Merge Sort와 스택의 결합**

`push_swap`에서 Merge Sort를 적용하기 위해 스택을 사용합니다. 스택 `a`에 있는 데이터를 분할하고 스택 `b`를 활용하여 정렬된 데이터를 병합하는 과정으로 구현됩니다.

#### **알고리즘 흐름:**

1. **스택 분할**: 스택 `a`에 있는 데이터를 스택 `b`로 반씩 나누어 이동시킵니다.
2. **재귀적 정렬**: 스택 `a`와 `b`에 있는 데이터를 각각 정렬합니다.
3. **병합**: 스택 `b`에서 정렬된 데이터를 다시 스택 `a`로 병합하여 최종 정렬된 상태를 만듭니다.

#### **Merge Sort 구현 코드 예시**:

```c
void merge_sort_stack(Stack *a, Stack *b)
{
    if (a->size <= 1) return;

    // 스택을 반으로 나누어 스택 b로 옮기기
    split_stack(a, b);

    // 재귀적으로 스택 a와 b를 정렬
    merge_sort_stack(a, b);
    merge_sort_stack(b, a);

    // 두 스택을 다시 병합
    merge_stacks(a, b);
}

void split_stack(Stack *a, Stack *b) {
    int half_size = a->size / 2;
    for (int i = 0; i < half_size; i++) {
        push(b, pop(a)); // 스택 a에서 b로 데이터 이동
    }
}

void merge_stacks(Stack *a, Stack *b) {
    // 스택 b에서 정렬된 데이터를 다시 스택 a로 병합
    while (!is_empty(b)) {
        if (peek(a) < peek(b)) {
            rotate(a);
        } else {
            push(a, pop(b));
        }
    }
}
```


## 🧠 시간 복잡도 (Big-O Notation)

Merge Sort는 평균 및 최악의 경우 모두 **O(n log n)**의 시간 복잡도를 가지며, `push_swap`에서 매우 효율적인 정렬 방법입니다.

- **O(n)**: 병합 과정에서 두 리스트를 병합할 때 필요한 시간.
- **O(log n)**: 재귀적으로 리스트를 분할하는 과정.


## 📊 Merge Sort 과정 이미지 첨부

![image](https://github.com/user-attachments/assets/97885a5b-e547-4bca-afe3-e6d4b12b6864)

위 이미지는 Merge Sort를 하기 위해 스택을 나누는 방법을 도식화한 것입니다. 스택 `a`에 있는 데이터를 나누고, 스택 `b`에 데이터를 옮긴 후 병합하여 최종적으로 정렬된 스택을 완성하는 과정을 보여줍니다.


## 🧠 메모리 릭 방지 및 관리

Merge Sort와 같이 스택을 사용하는 알고리즘에서는 동적으로 할당된 메모리를 정확하게 해제해야 합니다. 이를 위해 `push_swap`에서 모든 동적 메모리는 프로그램 종료 시 반드시 `free()` 함수를 사용해 해제해야 합니다.

**메모리 릭 확인 방법**:

```c
#include <stdlib.h>

void check_leaks(void) {
    system("leaks push_swap");
}

int main(void) {
    atexit(check_leaks);  // 프로그램 종료 시 메모리 릭 확인
    // ... 나머지 프로그램 로직
}
```


## 🛠️ 프로젝트 빌드 및 테스트

### 1. **Makefile 사용법**

- `make`: 프로젝트를 컴파일하여 실행 파일을 생성합니다.
- `make clean`: 컴파일 후 생성된 오브젝트 파일들을 삭제합니다.
- `make fclean`: 오브젝트 파일과 실행 파일을 모두 삭제합니다.
- `make re`: 클린 후 다시 빌드합니다.

### 2. **테스트 방법**

1. `push_swap` 프로그램을 빌드한 후, 다양한 데이터셋에 대해 프로그램을 테스트하여 성능과 정확성을 검증합니다.
2. 특히, 대규모 데이터에서 Merge Sort가 어떻게 동작하는지 확인하며, 최적의 성능을 발휘하는지 점검합니다.


## 참고 문서

