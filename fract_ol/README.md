<h1 align="center">
	🌈 fract_ol 
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 📘 프로젝트 소개

`fract_ol` 프로젝트는 MiniLibX(mlx)를 사용하여 다양한 프랙탈(Fractal)을 그리는 프로그램입니다. 이 프로젝트는 프랙탈에 대한 수학적 이해와 함께, 그래픽 프로그래밍에 필요한 X-Window / Cocoa 환경에서의 창 생성, 이벤트 처리, 동적 라이브러리 사용법을 학습하는 것을 목표로 합니다. 이를 통해 복잡한 수학적 패턴을 시각적으로 표현하고, 상호작용할 수 있는 프로그램을 구현하게 됩니다.


## 💻 필수 구현 사항

- **프랙탈 그리기**:
  - 주어진 프랙탈(Mandelbrot, Julia 등)을 그래픽 창에 그리기
  - 마우스와 키보드를 이용한 줌인/줌아웃 기능 구현
  - 프로그램 종료 시 모든 동적 메모리를 해제하고 리소스를 정리
  

## ⚙️ 사용법

프랙탈을 그리는 `fract_ol` 프로그램은 다음과 같은 형식으로 실행할 수 있습니다:

```bash
./fract_ol Mandelbrot
./fract_ol Julia [추가 옵션]
```

**기본 명령어**:
- `./fract_ol Mandelbrot`: Mandelbrot 프랙탈을 그립니다.
- `./fract_ol Julia`: Julia 프랙탈을 그립니다.

**마우스 조작**:
- 스크롤: 줌인/줌아웃
- 좌/우 클릭: 창의 중심 이동


## 📂 주요 개념

### 1. **프랙탈 (Fractal)**

프랙탈은 동일한 패턴이 반복되는 구조를 가진 기하학적 도형을 의미합니다. `fract_ol` 프로젝트에서는 Mandelbrot 집합과 Julia 집합을 구현합니다.

- **Mandelbrot 집합**: 복소수 평면에서 정의되는 프랙탈로, 주어진 수식에서 발산하지 않는 복소수의 집합을 표현합니다.
- **Julia 집합**: Mandelbrot 집합과 유사하지만, 초기 조건에 따라 다양한 형태의 프랙탈을 생성할 수 있습니다.

#### **Mandelbrot 수식**:

Mandelbrot 집합은 다음의 반복적인 복소수 함수에 의해 정의됩니다:

```math
Z_{n+1} = Z_n^2 + C
```

여기서 `C`는 복소수이며, 반복을 통해 발산하지 않는 `Z_n`의 값들을 집합으로 만듭니다.


### 2. **MiniLibX (mlx) 사용법**

`MiniLibX`는 X-Window / Cocoa 프로그래밍 지식 없이 간단한 창 생성, 이미지 그리기 및 이벤트 처리를 쉽게 할 수 있는 라이브러리입니다. `fract_ol`은 MiniLibX를 사용하여 프랙탈을 시각적으로 표현합니다.

#### **MiniLibX 주요 함수**:

- **mlx_init()**: 그래픽 창과 display를 초기화하는 함수입니다.
- **mlx_new_window()**: 새로운 창을 생성합니다.
- **mlx_new_image()**: 이미지를 메모리 상에 생성하고 다룰 수 있게 합니다.
- **mlx_put_image_to_window()**: 생성된 이미지를 창에 표시합니다.
- **mlx_hook()**: 마우스나 키보드 이벤트를 처리할 수 있도록 함수를 연결합니다.
- **mlx_loop()**: 이벤트를 지속적으로 처리하기 위한 루프를 실행합니다.

#### **프랙탈 그리기 예시**:

```c
void draw_fractal(t_data *data)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            int color = calculate_color(x, y);
            mlx_pixel_put(data->mlx, data->win, x, y, color);
        }
    }
}
```

### 3. **동적 라이브러리 사용**

프로그램 실행 중에 필요한 라이브러리를 동적으로 로드하여 사용하는 방식입니다. `fract_ol`에서는 MiniLibX 라이브러리를 동적으로 사용합니다. 라이브러리는 `dlopen()`과 `dlsym()`을 통해 로드 및 사용 가능합니다.


## 📊 프랙탈 패턴 및 이미지

프랙탈을 그릴 때 생성되는 복잡한 패턴은 다음과 같은 방식으로 시각화할 수 있습니다.

![image](https://github.com/user-attachments/assets/bf1d36bb-c8e7-42f1-a2ce-cac7e807c453)

위 이미지는 Mandelbrot 프랙탈의 기본적인 형태입니다. 중심부로 갈수록 복잡한 패턴이 반복되며, 무한대로 확대해도 동일한 패턴이 반복적으로 나타납니다. 이와 같은 패턴은 컴퓨터의 복소수 연산을 통해 계산되며, 각 픽셀의 색상은 발산 여부에 따라 결정됩니다.


## 🧠 키보드 및 마우스 이벤트 처리

`fract_ol`은 키보드와 마우스를 통해 사용자와 상호작용합니다.

- **줌인/줌아웃**: 마우스 휠을 사용하여 프랙탈의 특정 영역을 확대 또는 축소합니다.
- **이동**: 키보드 화살표 키를 사용하여 화면을 상하좌우로 이동할 수 있습니다.
- **프로그램 종료**: ESC 키를 누르면 프로그램을 종료할 수 있습니다.

#### **이벤트 처리 코드 예시**:

```c
int handle_key(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
        exit_program(data);
    else if (keycode == UP_ARROW)
        move_up(data);
    else if (keycode == DOWN_ARROW)
        move_down(data);
    return (0);
}
```


## 🧠 메모리 관리 및 리소스 해제

프로그래밍에서 동적으로 할당된 메모리를 적절히 해제하지 않으면 메모리 릭이 발생할 수 있습니다. `fract_ol`에서는 프로그램 종료 시 모든 동적 메모리와 그래픽 리소스를 해제해야 합니다.

```c
void free_resources(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    free(data);
}
```


## 🛠️ 프로젝트 빌드 및 테스트

### 1. **Makefile 사용법**

`Makefile`을 사용하여 프로젝트를 쉽게 빌드하고 관리할 수 있습니다.

- `make`: 프로그램을 컴파일하고 실행 파일을 생성합니다.
- `make clean`: 오브젝트 파일을 삭제합니다.
- `make fclean`: 오브젝트 파일 및 실행 파일을 모두 삭제합니다.
- `make re`: 클린 후 다시 빌드합니다.

### 2. **테스트**

프로그램 실행 후 다양한 프랙탈을 시각적으로 확인하고, 줌인/줌아웃 및 이동 기능을 테스트하여 프로그램이 올바르게 동작하는지 검증합니다.


## 참고 문서

- [MiniLibX 라이브러리](https://harm-smits.github.io/42docs/libs/minilibx)
- [Mandelbrot 집합](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Fractal Zoom Algorithm](https://www.alanzucconi.com/2016/05/03/how-to-colour-the-mandelbrot-set/)