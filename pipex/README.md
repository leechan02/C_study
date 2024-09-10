<h1 align="center">
	🪈 pipex
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 📘 프로젝트 소개

`pipex`는 두 명령어를 파이프를 통해 연결하여, 첫 번째 명령어의 출력을 두 번째 명령어의 입력으로 전달하는 프로그램입니다. 이를 통해 프로세스 간 통신(Inter-Process Communication, IPC)을 구현하며, 파이프와 파일 디스크립터, 프로세스 생성 및 제어에 대한 이해를 심화하는 것을 목표로 합니다. 또한, 리다이렉션과 환경 변수를 처리하여 다양한 입력과 출력을 효과적으로 제어할 수 있습니다.


## 💻 필수 구현 사항

- **기능 설명**:
  - `pipex`는 두 명령어를 파이프(`pipe()`)로 연결하여, 하나의 명령어 출력이 다음 명령어의 입력으로 전달되도록 합니다.
  - 각 명령어는 `fork()`로 새로운 프로세스를 생성하여 실행되고, `dup2()`를 통해 파일 디스크립터를 적절히 설정하여 입력과 출력을 제어합니다.
  - 파이프 외에도 리다이렉션, 환경 변수 처리, 파일 디스크립터 관리 등을 다룹니다.


## ⚙️ 사용법

기본적인 `pipex` 실행 방법:

```bash
./pipex infile "command1" "command2" outfile
```

- **infile**: 첫 번째 명령어의 입력 파일
- **command1**: 첫 번째 실행 명령어
- **command2**: 두 번째 실행 명령어
- **outfile**: 두 번째 명령어의 출력 파일

예시:

```bash
$ ./pipex input.txt "grep keyword" "wc -l" output.txt
```

이 명령어는 `input.txt`에서 `grep keyword`를 실행한 결과를 `wc -l`로 전달하고, 그 결과를 `output.txt`에 저장합니다.


## 📂 주요 개념

### 1. **Inter-Process Communication (IPC)**

- IPC는 두 개 이상의 프로세스 간에 데이터를 주고받기 위한 방법을 의미합니다. 파이프는 프로세스 간의 통신을 위해 자주 사용되는 방식 중 하나로, 데이터를 스트림 형태로 전달합니다.

### 2. **파이프 (Pipe)**

파이프는 한 프로세스의 출력을 다른 프로세스의 입력으로 전달하는 통신 방식입니다. `pipex`는 이 구조를 사용하여 명령어들을 연결합니다.

- **파이프 구현 원리**:
  1. `pipe()` 시스템 호출로 두 개의 파일 디스크립터(읽기 및 쓰기) 생성.
  2. `fork()`로 자식 프로세스 생성 후, `dup2()`로 표준 입력/출력을 파이프의 읽기/쓰기 쪽에 재지정.
  3. 명령어 실행 후, 부모 프로세스는 자식이 종료될 때까지 대기.

### 3. **fork와 exec**

- **fork()**: 현재 프로세스를 복사하여 자식 프로세스를 생성합니다.
- **execve()**: 새로운 프로그램을 실행하며, 기존 프로세스를 대체합니다.

### 4. **리다이렉션 (Redirection)**

리다이렉션은 명령어의 입력 또는 출력을 파일로 보내거나, 다른 명령어의 입력으로 보낼 때 사용됩니다.

- **입력 리다이렉션**: `command < infile`
- **출력 리다이렉션**: `command > outfile`
- **히어독 (heredoc)**: 특정 구분자까지 입력을 받아 처리하는 리다이렉션 방식입니다.


## 🧠 메모리 관리 및 리소스 관리

### 1. **파일 디스크립터 관리**

- **파일 디스크립터(Table)**: 각 프로세스는 자신만의 파일 디스크립터 테이블을 가지고 있습니다. `pipex`에서는 표준 입력/출력(`stdin`, `stdout`)을 `dup2()`로 재지정하여 파이프를 통해 데이터를 주고받습니다.

### 2. **메모리 릭 방지**

- 메모리 및 파일 디스크립터를 올바르게 해제하지 않으면 메모리 릭 또는 리소스 고갈이 발생할 수 있습니다. `pipex`는 동적으로 할당된 메모리를 반드시 해제하고, 모든 파일 디스크립터를 닫아야 합니다.


## 🛠️ 프로젝트 구성

### 1. **파일 입출력**

```c
int openfile(char *filename, int mode)
{
    int fd = open(filename, mode);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fd;
}
```

### 2. **명령어 실행**

```c
void exec_command(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    if (execve(args[0], args, envp) == -1)
    {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }
}
```

### 3. **파이프와 프로세스 제어**

```c
void pipe_process(char *cmd, char **envp, int fd_in, int fd_out)
{
    pid_t pid = fork();
    if (pid == 0) // 자식 프로세스
    {
        dup2(fd_in, STDIN_FILENO);  // 입력 재지정
        dup2(fd_out, STDOUT_FILENO); // 출력 재지정
        exec_command(cmd, envp);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0); // 부모는 자식이 종료될 때까지 대기
    }
    else
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
}
```


## 🛠️ Makefile 사용법

- `make`: 프로젝트를 컴파일하여 실행 파일을 생성합니다.
- `make clean`: 생성된 오브젝트 파일들을 삭제합니다.
- `make fclean`: 오브젝트 파일 및 실행 파일을 삭제합니다.
- `make re`: 클린 후 다시 빌드합니다.


## 참고 문서

- [man 2 pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [man 2 dup2](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html)
