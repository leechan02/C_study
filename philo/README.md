<h1 align="center">
	🎅 philosophers
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 📘 프로젝트 소개

`philo` 프로젝트는 철학자 문제(Dining Philosophers Problem)를 기반으로 스레드(Thread)와 뮤텍스(Mutex)를 사용하여 프로세스의 동기화와 병렬 처리에 대한 개념을 배우는 프로젝트입니다. 이 문제는 철학자들이 식사하고 생각하며 반복하는 과정에서 발생하는 동기화 문제를 해결하는 방법을 학습하는 데 중점을 둡니다.


## 💡 주요 목표

- **스레드와 프로세스 관리**: 스레드와 프로세스 간의 차이를 이해하고, 병렬 프로그래밍에서 발생하는 동기화 문제를 해결하는 방법을 배웁니다.
- **스레드 생성 및 동기화**: `pthread` 라이브러리를 사용하여 스레드를 생성하고, 뮤텍스를 이용해 경쟁 상태(race condition)를 방지합니다.
- **철학자 문제 해결**: 철학자들이 식사와 생각을 반복하며, 교착 상태(deadlock) 없이 문제를 해결하는 방법을 구현합니다.


## 📂 주요 개념

### 1. **철학자 문제 (Dining Philosophers Problem)**

철학자 문제는 다중 스레드 프로그래밍에서 동기화 문제를 설명하는 데 자주 사용되는 예제입니다. 철학자들이 원형 테이블에 앉아 있고, 각 철학자는 식사를 하거나 생각을 합니다. 식사하려면 양옆의 두 개의 포크를 집어야 하고, 한 번에 하나씩만 포크를 집을 수 있습니다. 이 과정에서 교착 상태가 발생하지 않도록 해야 합니다.

- **상태 전환**: 철학자는 다음과 같은 순서로 상태를 전환합니다:
  - **생각** → **배고픔** → **식사** → **잠** → 다시 **생각**
- **제한사항**: 철학자가 죽지 않도록 해야 하며, 철학자들이 식사를 하지 않고 너무 오랫동안 기다리지 않도록 합니다.

### 2. **스레드와 프로세스**

`philo` 프로젝트는 철학자마다 하나의 스레드를 생성하여 각 스레드가 독립적으로 작업을 처리하도록 합니다. 멀티스레딩의 개념을 이해하고, 스레드 간의 동기화 문제를 해결하는 방법을 학습합니다.

- **멀티스레드**: 하나의 프로세스 내에서 여러 스레드가 동시에 실행됩니다.
- **뮤텍스(Mutex)**: 스레드 간의 동기화를 위해 사용되며, 한 번에 하나의 스레드만 공유 자원에 접근할 수 있도록 제어합니다.


## 📊 철학자 문제 해결

### 1. **스레드 생성 및 관리**

철학자들은 각각 독립적인 스레드로 실행됩니다. 각 스레드는 식사하고, 생각하고, 잠을 자는 행동을 무한 반복합니다.

```c
void *philosopher_routine(void *arg) {
    philosopher_t *philo = (philosopher_t *)arg;
    while (1) {
        think(philo);
        take_forks(philo);
        eat(philo);
        put_forks(philo);
        sleep(philo);
    }
    return NULL;
}
```

### 2. **뮤텍스를 이용한 동기화**

각 철학자는 양쪽의 포크(뮤텍스)를 사용해야 식사를 할 수 있습니다. 포크를 사용하기 전에는 반드시 뮤텍스를 잠가 다른 철학자가 동시에 포크를 사용할 수 없도록 해야 합니다.

```c
pthread_mutex_lock(&forks[left_fork]);
pthread_mutex_lock(&forks[right_fork]);

// 식사 중

pthread_mutex_unlock(&forks[left_fork]);
pthread_mutex_unlock(&forks[right_fork]);
```

### 3. **교착 상태(deadlock) 방지**

교착 상태를 방지하기 위해 철학자가 포크를 획득하지 못했을 경우, 대기 시간을 두고 다시 시도하거나 포크를 놓는 등의 방법을 사용할 수 있습니다.


## 🧠 프로그램 동작

### 1. **프로그램 실행 방법**

다음과 같은 형식으로 `philo` 프로그램을 실행할 수 있습니다:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**예시**:
```bash
./philo 5 800 200 200
```

이 명령어는 5명의 철학자가 800ms 동안 먹지 않으면 죽고, 200ms 동안 먹고, 200ms 동안 자는 시뮬레이션을 실행합니다.

### 2. **출력**

프로그램이 실행되면 철학자의 상태가 시간에 따라 다음과 같이 출력됩니다:

```bash
timestamp philosopher_number has taken a fork
timestamp philosopher_number is eating
timestamp philosopher_number is sleeping
timestamp philosopher_number is thinking
timestamp philosopher_number died
```


## 🛠️ 주요 함수 및 기능

### 1. **스레드 관련 함수**

- **pthread_create()**: 새로운 스레드를 생성하여 철학자의 행동을 담당하는 함수를 실행합니다.
- **pthread_join()**: 스레드가 종료될 때까지 대기합니다.
- **pthread_detach()**: 스레드가 끝나면 자동으로 자원을 반환합니다.

### 2. **뮤텍스 관련 함수**

- **pthread_mutex_init()**: 각 포크에 대한 뮤텍스를 초기화합니다.
- **pthread_mutex_lock()**: 특정 뮤텍스를 잠가 해당 자원에 대한 접근을 제한합니다.
- **pthread_mutex_unlock()**: 뮤텍스를 해제하여 다른 스레드가 자원에 접근할 수 있게 합니다.
- **pthread_mutex_destroy()**: 사용이 끝난 뮤텍스를 해제합니다.


## 📋 중요한 개념

### 1. **멀티스레딩**

멀티스레딩은 하나의 프로세스 내에서 여러 스레드를 실행하여 병렬 작업을 처리할 수 있도록 하는 기법입니다. 이를 통해 CPU 자원을 효율적으로 활용하고 프로그램의 성능을 향상시킬 수 있습니다.

### 2. **동기화 문제 (Synchronization Issues)**

여러 스레드가 동시에 같은 자원에 접근할 때 발생할 수 있는 문제를 동기화 문제라고 합니다. 이를 해결하기 위해 뮤텍스와 세마포어와 같은 동기화 기법을 사용합니다.


## 📚 참고 자료

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [Mutex and Semaphore](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
