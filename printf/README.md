<h1 align="center">
	🖋️ ft_printf
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 개요

`ft_printf` 프로젝트는 C 표준 라이브러리의 `printf` 함수 구현을 목표. 다양한 데이터 타입(문자, 문자열, 정수, 포인터 등)에 대해 서식을 지정하여 출력할 수 있는 기능을 제공.

### **필수 구현 사항**
- 다음 서식 지정자를 지원: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`
- `ar` 명령어를 이용하여 라이브러리(`libftprintf.a`)를 생성. `libtool` 사용은 금지.
- 원본 `printf()`의 버퍼 관리 기능은 구현되지 안됨.

### **추가 구현 사항 (보너스)**
- 플래그 `-`, `0`, `.`을 추가로 지원.
- `width`와 플래그 `#`, `+`, 공백 지원.

### **참고 문서**
- [man 3 printf](https://linux.die.net/man/3/printf)
- [man 3 stdarg](https://linux.die.net/man/3/stdarg)

## 주요 개념

### 가변 인자 (Variable Arguments)
이 프로젝트는 가변 인자를 사용하여 함수가 다양한 개수의 인수를 받을 수 있도록 구현됨. 이는 `va_list`와 관련된 매크로들(`va_start`, `va_arg`, `va_end`)을 사용하여 처리.

```c
#include <stdarg.h> // va_list, va_start, va_arg, va_end 매크로

void func(int num_args, ...); // 최소 하나 이상의 고정 인자가 필요.
```

### 서식 지정자 (Format Specifiers)
다음 서식 지정자들을 구현:
- `%c`: 문자
- `%s`: 문자열
- `%p`: 포인터 (16진수로 출력)
- `%d`, `%i`: 부호 있는 10진수 정수
- `%u`: 부호 없는 10진수 정수
- `%x`, `%X`: 부호 없는 16진수 정수
- `%%`: 퍼센트 기호 출력

### 서식 플래그 (Format Flags)
- `-`: 주어진 필드 너비 내에서 왼쪽 정렬
- `+`: 숫자 앞에 항상 부호(`+` 또는 `-`)를 표시
- `0`: 빈 공간을 0으로 채움
- `#`: 16진수 앞에 `0x` 또는 `0X` 접두어 추가
- 공백: 부호가 없는 양수 앞에 공백을 추가

### 버퍼 관리
- `printf()` 같은 표준 입출력 함수들은 효율성을 위해 메모리 버퍼를 사용하지만, 이 프로젝트에서는 버퍼 관리를 구현 안함.

## 비트 플래그 처리
플래그는 비트 연산자를 사용하여 처리되며, 비트 조작을 통해 플래그를 효율적으로 관리.

```c
unsigned int flags = 0;
flags |= 1 << 1;  // 플래그 설정
if (flags & (1 << 1)) { /* 플래그 확인 */ }
flags &= ~(1 << 1);  // 플래그 해제
```

## Makefile 사용법

- `make`: 프로젝트를 컴파일하고 `libftprintf.a` 라이브러리를 생성.
- `make bonus`: 보너스 플래그와 추가 서식 지정자를 포함하여 컴파일.
- `make clean`: 오브젝트 파일을 삭제.
- `make fclean`: 오브젝트 파일 및 라이브러리를 삭제.
- `make re`: 클린 후 다시 빌드.
