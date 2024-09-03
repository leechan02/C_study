# Part1

## strlcpy

```c
#include <string.h>

size_t
ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
```

### ✔️ Description

- `src`문자열을 `dst`에 `dstzise`만큼 복사를 하는 함수이다.
- `dstsize`에 -1이 붙은 이유는 복사를 진행한 후에 NULL값을 붙여주기 위함이다.
- `strlcpy`는 `strncpy`의 단점을 보안한 조금 더 안전한 함수다.
- `src > dstsize`의 경우는 `dstsize`의 길이가 0보다 크기만 하면 무조건 끝자리에 NULL문자를 붙여준다.

### ✔️ Return

- 복사할 문자열의 길이(`src`의 길이)

## strlcat

```c
#include <string.h>

size_t
strlcat(char * dst, const char * src, size_t dstsize);
```

### ✔️ Description

- `src`를 `dst`에 붙여서 `dstsize`를 만드는 함수이다.

### ✔️Return

- `size`가 `dest`의 크기보다 작을 때, **strlen(src) + size를 리턴**한다.
- `size`가 `dest`의 크기보다 클 때, **strlen(src) + strlen(dest)를 리턴**한다.

## strlen

## memset

```c
#include <string.h>

void *
memset(void *b, int c, size_t len)
```

### ✔️ Description

- 메모리 블록을 채운다.
- memset()함수는 `b` 가 가리키는 메모리 주소부터 `len` 바이트만큼 `c`값을 채운다.
- `c` 는 `unsigned char` 로 형변환된다. 따라서 `int`값으로 초기화는 불가능하다! 형 변환이 되는 이유는 반환값이 `void` 포인터형이라서 `int`형과 `char`형 모두 받을 수 있지만, `int`는 `4byte`고 `memset`은 `1byte`씩 적용을 해 `int`형은 제대로 적용이 힘들다.

### ✔️ Return

- 복사완료된 문자열의 주소 `b` 를 리턴한다.

## bzero

```c
#include <string.h>

void
bzero(void *s, size_t n)
```

### ✔️ Description

- bzero()함수는 `s`가 가리키는 메모리로부터 `n`바이트만큼 `0`값을 채운다.

### ✔️ Return

- `none`

## memcpy

```c
#include <string.h>

void	*
ft_memcpy(void *dst, const void *src, size_t n)
```

### ✔️ Description

- 메모리의 일부분을 복사한다.
- `src`가 가리키는 곳 부터 `size`바이트만큼 `dest`에 복사한다.
- 오버플로우 문제를 방지하기 위해 `dst`과 `src`가 가리키는 배열의 크기는 반드시 `n`바이트 이상이여야 하며, 서로 겹치면 안된다. (만일 두 메모리 블록이 겹쳐져 있다면 `memmove`함수를 이용하는 것이 현명하다.)

### ✔️ Return

- 성공시 `dst` 리턴.
- `dst`와 `src`가 모두 `NULL`이면 `0(NULL 포인터)` 리턴.

## memmove

```c
#include <string.h>

void *
ft_memmove(void *dst, const void *src, size_t len)
```

### ✔️ Description

- 메모리의 블록을 옮긴다.
- `src` 가 가리키는 곳 부터 `size` 바이트 만큼 `dest` 가 가리키는 곳으로 옮긴다.
- 오버플로우를 방지하기 위해 `dst`와 `src`가 가리키는 배열 모두 적어도 `len`바이트 이상은 되어야 한다.

### ✔️ Return

- 성공시 복사된 문자역 시작 주소(`dst`)
- `dst`와 `src`가 모두 `NULL`이면 `0(NULL 포인터)` 리턴.

## memchr

```c
#incldue <string.h>

void	*
ft_memchr(const void *s, int c, size_t n)
```

### ✔️ Description

- 메모리 블록에서의 문자를 찾는다.
- `s` 이 가리키는 메모리의 처음 `n` 바이트 중에서 처음으로 `c` 와 일치하는 값의 주소를 리턴한다.

### ✔️ Return

- 메모리 블록에서 `c`와 일치하는 값이 있다면 그 곳의 주소를 리턴.
- 값을 찾지 못한다면 `NULL`을 리턴.

## calloc

```c
#incldue <stdlib.h>

void *
calloc(size_t count, size_t size)
```

### ✔️ Description

- 각각 메모리의 크기 바이트인 `count` 객체에 대해 충분한 공간을 연속적으로 할당하고 할당된 메모리는 값이 0인 바이트로 채워집니다.

### ✔️ Return

- 할당된 메모리에 대한 포인터를 반환합니다.

## strchr

```c
#include <string.h>

char* 
strrchr(const char *s, int c);
```

### ✔️ Description

- `s`가 가리키는 문자열에서 첫번째 `c` (`char`로 변환)를 찾는다.
- `c`는 검색할 문자를 의미하고 `int`로 형 변환 되어서 전달되지만, 함수 내부적으로 다시 `char`로 처리된다.

### ✔️ Return

- 찾은 문자 포인터를 리턴.
- 만일 문자가 없다면 `NULL` 포인터를 리턴.

## strrchr

```c
#include <string.h>

char* 
strrchr(const char *s, int c);
```

### ✔️ Description

- `s`가 가리키는 문자열에서 마지막 `c` (`char`로 변환)를 찾는다.
- `c`는 검색할 문자를 의미하고 `int`로 형 변환 되어서 전달되지만, 함수 내부적으로 다시 `char`로 처리된다.

### ✔️ Return

- 찾은 문자 포인터를 리턴.
- 만일 문자가 없다면 `NULL` 포인터를 리턴.

## strnstr

```c
#include <string.h>

char *
strnstr(const char *haystack, const char *needle, size_t len);
```

### ✔️ Description

- 문자열 `haystack`에서 길이 `len내에 needle이 있는지` 검사를 하는 함수이다.

### ✔️ Return

- 만약 찾았다면 찾은 지점의 포인터를 반환하고 만약 못 찾았다면 `NULL`을 반환한다.
- 우리가 찾아야 할 문자열이 `빈 문자열`이라면("\0") `haystack을 그대로 반환`해 준다.

## strdup

## atoi

```c
#include <stdlib.h>

int
atoi(const char *str)
```

## memcmp

```c
#incldue <string.h>

int	
ft_memcmp(const void *s1, const void *s2, size_t n)
```

### ✔️ Description

- 두 메모리 블록을 비교한다.

### ✔️ Return

- 만일 두 메모리 블록이 정확히 같다면 0 을 리턴한다.
- 만일 두 메모리 블록이 다를 경우, `s1` 과 `s2` 가 가리키는 메모리 블록에서 앞에서 부터 처음으로 다른 바이트를 살펴 보는데, 그 바이트를 `unsigned char` 로 해석하였을 때, 그 값이 `s1` 이 더 크면 0 보다 큰 값을, 아니면 0 보다 작은 값을 리턴한다.

## strncmp

```c
#include <string.h>

int
strncmp(const char *s1, const char *s2, size_t n);
```

### ✔️ Description

- 두 문자열을 원하는 길이까지만 비교하는 함수.

### ✔️ Return

- 만일 `n`개의 문자가 모두 일치하면, `0`을 리턴.
- 비교한 `n`개의 문자 중 최초로 일치하지 않는 문자의 값이 `s1`이 더 큰 경우 `0보다 큰 값`을, `s2`가 더 큰 경우 `0보다 작은 값`을 리턴.
- 즉 `s1`의 값과 `s2`의 값의 차를 리턴. unsigned char로 해주지 않으면 결과값이 확장 아스키 코드가 들어올 경우 오버플로우 때문에 캐스팅 필요.

## isalnum

## isalpha

## isdigit

## isascii

## isprint

## toupper

## tolower

# Part2

## substr

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

### ✔️ Description

- `s[start]` 에서부터 `len`만큼의 길이만큼 복제하여 반환하는 함수.

### ✔️ Return

- `s[0]` 일 때는 `return 0;`
- 문자열의 길이보다 `start 값이 클 경우` `빈 문자열을 반환`한다.
- 복사할 문자열의 길이가 len보다 짧으면 그만큼만 복사 후 반환한다.

## strjoin

```c
char *ft_strjoin(char const *s1, char const *s2);
```

### ✔️ Description

- s1과 s2를 연결한 `새로운 문자열`을 반환한다.

### ✔️ Return

- s1, s2 `전부 널이면 0`을 반환한다.
- `하나만 널`일경우 `나머지 문자열만 복제`하여 반환한다.

## strtrim

```c
char *ft_strtrim(char const *s1, char const *set);
```

### ✔️ Description

- `s1`에서 문자열의 시작과 끝에서 `set에 지정된 문자들을 제거`한 문자열을 새로 복제하여 반환한다.
- `s1`의 앞뒤로 `set`에 들어간 문자는 모두 삭제한 뒤 반환하는 함수
    
    ex) s1 = ABCEDFG set = AEFG return = ~~A~~`BCDEB`~~FG~~
    

### ✔️ Return

- s1이 널이면 `0`을 반환한다.
- set이 널이면 `s1을 복제`하여 반환한다.

## split

```c
char **ft_split(char const *s, char c);
```

### ✔️ Description

- 구분문자 c를 활용하여, s문자열을 분할하고 `이차원 배열`에 저장하여 반환한다.
- 이때 배열은 `null`로 끝나야 한다.

### ✔️ Return

- 맨 끝에 null이 들어간 이차원 배열.

## itoa

```c
char *ft_itoa(int n);
```

### ✔️ Description

- 인수로 받은 정수를 문자열로 치환하여 반환한다. 음수가 고려되어야 한다.

### ✔️ Return

- 문자열

## **strmapi**

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

### ✔️ Description

- 문자열 s를 복제하는데, 내부 데이터를 문자열 s의 각 데이터를 f에 넣어 받은 값으로 채운다.`s[0] ⇒ t[f(s[0])]`

### ✔️ Return

- 원본 문자열에서 함수 `'f'`를 성공적으로 적용하여 생성된 결과 문자열. 할당 실패 시, `NULL`

## striteri

```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

### ✔️ Description

- 문자열 `s`에 들어있는 각 인자에 `f`함수를 적용시킨다.

### ✔️ Return

- `none`

## putchar_fd

```c
void ft_putchar_fd(char c, int fd);
```

### ✔️ Description

- file descripter에 작성.

### ✔️ Return

- `none`

### !! Notice

- 기본적으로 할당되는 파일디스크립터는 표준입력(Standard Input), 표준 출력(Standard Output), 표준에러(Standard Error)이며 이들에게 각각 0, 1, 2라는 정수가 할당된다.
- 파일 디스크립터(File Descriptor)란 리눅스 혹은 유닉스 계열의 시스템에서 프로세스(process)가 파일(file)을 다룰 때 사용하는 개념으로, 프로세스에서 특정 파일에 접근할 때 사용하는 추상적인 값이다. **파일 디스크럽터는 일반적으로 0이 아닌 정수값을 갖는다.**

## putstr_fd

```c
void ft_putstr_fd(char *s, int fd);
```

### ✔️ Description

- 얘도 putstr과 같지만 특정한 파일의 번호를 가져와서 그 파일에 접근해서 입력한다.

### ✔️ Return

- `none`

## putendl_fd

```c
void ft_putendl_fd(char *s, int fd);
```

### ✔️ Description

- 문자열 `s` 출력하고 개행을 출력한다.

### ✔️ Return

- `none`

## putnbr_fd

```c
void ft_putnbr_fd(int n, int fd);
```

### ✔️ Description

- putnbr과 같지만 파일디스크립터이다.

### ✔️ Return

- `none`

# Bonus

## lstnew

```c
t_list *ft_lstnew(void *content);
```

### ✔️ Description

- • **lstnew함수**는 **첫 노드를 생성**하는 함수.

### ✔️ Return

- 새로 만든 list의 포인터를 반환한다.

### !! Notice

- **연결리스트(linked list)**는 각 노드가 **데이터**와 **포인터**를 가지고 한 줄로 연결되어 있는 방식으로 **데이터를 저장**하는 **자료 구조이고,** • 연결 리스트의 노드는 구조체의 형태를 띠고 있다.

```c
typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}t_list
```

- **연결 리스트의 각 자료**를 **노드(node)**라고 부릅니다.
- 필요에 따라 **동적 메모리**를 별도로 할당하여 **노드**를 만듭니다.
- 각 노드에 있는 **포인터 변수**에 **다음 노드의 메모리 주소**를 저장하고 제일 **마지막 노드**는 **NULL포인터**를 저장합니다.
- **메모리 관리**능력과 **이중 포인터**사용 능력이 요구되는 **자료 구조**입니다.

## lstadd_front

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

### ✔️ Description

- • **lstadd_front함수**는 **앞쪽에 새로운 노드를 추가**하는 함수.

### ✔️ Return

- `none`

## lstsize

```c
 int ft_lstsize(t_list *lst);
```

### ✔️ Description

- • **lstsize함수**는 **노드의 갯수**를 새어주는 함수입니다.

### ✔️ Return

- lst의 size를 리턴한다.

## lstlast

```c
t_list *ft_lstlast(t_list *lst);
```

### ✔️ Description

- • **lstlast함수**는 **마지막 노드의 주소**를 출력해주는 함수입니다.

### ✔️ Return

- 마지막 노드의 주소를 리턴.

## lstadd_back

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

### ✔️ Description

- • **lstadd_back함수**는 **뒤쪽에 새로운 노드를 추가**하는 함수입니다.

### ✔️ Return

- `none`

## lstdelone

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

### ✔️ Description

- **lstdelone함수**는 **특정 노드를 삭제**하는 함수입니다.

### ✔️ Return

- `none`

## lstclear

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

### ✔️ Description

- • **lstclear함수**는 **모든 노드를 삭제**하는 함수 입니다.

### ✔️ Return

- `none`

## lstiter

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

### ✔️ Description

- • **lstiter함수**는 노드의 모든 **요소**에 *지정한 함수**를 적용시키는 함수입니다.

### ✔️ Return

- `none`

## lstmap

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

### ✔️ Description

- • **lstmap함수**는 연결리스트의 **노드요소**들을 **지정한 함수**를 적용하여 **새로운 리스트와 노드에 복사**하는 함수입니다.

### ✔️ Return

- 새로운 리스트 주소 반환.

# Makefile

### case 1

```makefile
NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = ./libft.h
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c
SRCS_B = ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(TOTAL_OBJS)
	ar rcs $@ $^

bonus : 
	@make WITH_BONUS=1 all

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
```

### case 2

```makefile
NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = ./libft.h
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c
SRCS_B = ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcsu $@ $^

bonus : $(OBJS_B) $(OBJS)
	@ar -rcsu $(NAME) $^

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
```

### 라이브러리(아카이브) 생성

`r` : 지정한 오브젝트 파일이 새로운 파일이면 추가, 기존파일이면 치환한다.

`u` : 오브젝트 파일의 수정시간을 비교해서 새로운 파일일 경우에만 치환한다.

`c` : 라이브러리(아카이브) 생성시 기본적으로 표준 에러를 기록하여 진단 메세지를 출력하는데 해당 출력을 제한한다.

`s` : 아카이브 파일의 정보를 담는 인덱스를 생성한다.

> 아카이브 인덱스를 생성하지 않으면 링크 속도가 느려지고 시스템 환경에 따라서는 에러가 발생하기도 한다.
>
