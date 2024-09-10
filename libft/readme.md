<h1 align="center">
	🧰 libft
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 💡 프로젝트 소개

> _이 프로젝트는 C 라이브러리를 만드는 것에 관한 것입니다. 여러분의 프로그램이 의존하게 될 다양한 범용 함수들을 구현하게 될 것입니다._

C 언어 프로그래밍은 표준 함수에 접근할 수 없을 때 매우 번거로울 수 있습니다. 이 프로젝트는 이러한 함수들이 어떻게 작동하는지 이해하고, 이를 구현하며 사용하는 방법을 배우는 것입니다. 여러분은 직접 라이브러리를 만들게 됩니다. 이 라이브러리는 앞으로 진행할 다른 C 과제에서도 유용하게 사용될 것입니다.

이 라이브러리는 연중 계속 확장하는 것이 좋습니다. 그러나 새 프로젝트를 작업할 때는 라이브러리에서 사용하는 함수들이 프로젝트 지침에서 허용되는지 항상 확인해야 합니다.

## ⛓️ 함수 목록:

### 문자 검사 및 변환 함수

* [`ft_isalnum`](libft/ft_isalnum.c) - 영숫자 문자인지 확인합니다.
* [`ft_isalpha`](libft/ft_isalpha.c) - 알파벳 문자인지 확인합니다.
* [`ft_isascii`](libft/ft_isascii.c) - ASCII 문자인지 확인합니다.
* [`ft_isdigit`](libft/ft_isdigit.c) - 숫자(0에서 9까지)인지 확인합니다.
* [`ft_isprint`](libft/ft_isprint.c) - 출력 가능한 문자인지 확인합니다.
* [`ft_tolower`](libft/ft_tolower.c) - 대문자를 소문자로 변환합니다.
* [`ft_toupper`](libft/ft_toupper.c) - 소문자를 대문자로 변환합니다.

### 메모리 할당 및 변환 함수

* [`ft_atoi`](libft/ft_atoi.c) - 문자열의 시작 부분을 정수로 변환합니다.
* [`ft_calloc`](libft/ft_calloc.c) - 0으로 초기화된 메모리를 할당합니다.
* [`ft_itoa`](libft/ft_itoa.c) - 정수를 ASCII 문자열로 변환합니다.

### 메모리 처리 함수

* [`ft_memset`](libft/ft_memset.c) - 메모리 영역의 처음 n 바이트를 특정 값으로 채웁니다.
* [`ft_memcmp`](libft/ft_memcmp.c) - 두 메모리 영역을 비교합니다.
* [`ft_memcpy`](libft/ft_memcpy.c) - 메모리 영역을 복사합니다.

### 문자열 처리 함수

* [`ft_strlen`](libft/ft_strlen.c) - 문자열의 길이를 계산합니다.
* [`ft_strchr`](libft/ft_strchr.c) - 문자열에서 특정 문자의 첫 번째 발생을 찾습니다.
* [`ft_strrchr`](libft/ft_strrchr.c) - 문자열에서 특정 문자의 마지막 발생을 찾습니다.
* [`ft_strdup`](libft/ft_strdup.c) - 문자열을 복사합니다.
* [`ft_strjoin`](libft/ft_strjoin.c) - 두 문자열을 하나로 연결합니다.
* [`ft_split`](libft/ft_split.c) - 구분자로 문자열을 분리하여 문자열 배열로 만듭니다.
* [`ft_strtrim`](libft/ft_strtrim.c) - 문자열의 앞뒤 공백을 제거합니다.
* [`ft_strncmp`](libft/ft_strncmp.c) - 두 문자열을 최대 n 바이트만큼 비교합니다.

### 연결 리스트 함수

* [`ft_lstnew`](libft/ft_lstnew.c) - 새로운 리스트 노드를 생성합니다.
* [`ft_lstadd_front`](libft/ft_lstadd_front.c) - 리스트 앞에 새 노드를 추가합니다.
* [`ft_lstadd_back`](libft/ft_lstadd_back.c) - 리스트 끝에 새 노드를 추가합니다.
* [`ft_lstsize`](libft/ft_lstsize.c) - 리스트의 크기를 반환합니다.
* [`ft_lstlast`](libft/ft_lstlast.c) - 리스트의 마지막 노드를 반환합니다.
* [`ft_lstdelone`](libft/ft_lstdelone.c) - 리스트의 한 노드를 삭제합니다.
* [`ft_lstclear`](libft/ft_lstclear.c) - 리스트 전체를 삭제합니다.
* [`ft_lstiter`](libft/ft_lstiter.c) - 리스트의 각 노드에 주어진 함수를 적용합니다.
* [`ft_lstmap`](libft/ft_lstmap.c) - 리스트의 각 노드에 주어진 함수를 적용한 결과를 새로운 리스트로 반환합니다.


## 🛠️ 사용법

### 요구사항

이 라이브러리는 C 언어로 작성되었으며, 실행하려면 **`C` 컴파일러**와 일부 표준 **C 라이브러리**가 필요합니다.

### 사용법

**1. 라이브러리 컴파일**

라이브러리를 컴파일하려면 해당 경로로 이동한 후 다음 명령어를 실행하세요:

```shell
$ make
