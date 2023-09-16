# 🤖 Avoiding Obstacles Robot
> 길 안내 자율 주행 로봇 <br>

### Member & Main Work
- [김태경](https://github.com/Tigerfriend1) & [최상준](https://github.com/chaeso36) : 하드웨어(로봇 설계 및 제작)
- [강준우](https://github.com/June222) & [여지수](https://github.com/YeoJiSu) : 소프트웨어(알고리즘 개발 및 적용)


### 개발 환경 및 도구
- 개발 환경: [IAR Embedded Workbench](https://www.iar.com/kr/products/architectures/arm/iar-embedded-workbench-for-arm/)
- 사용 어플: [Serial Bluetooth Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=ko&gl=US&pli=1)
- 사용 도구: STM32F107VCT6 보드, 블루투스 모듈, 릴레이 모듈, 적외선 센서, TFT LCD, 4WD 주행로봇 프레임 세트, 건전지, 브레드보드, 전선

### 폴더 구조
```
Avoiding_Obstacles_Robot
├─ .git
├─ obstacle.c // 자율 주행 알고리즘 개발용 코드
└─ AvodingObstaclesRobot
   ├─ 📁 CoreSupport 
   ├─ 📁 Debug 
   ├─ 📁 Docs // 실험시 참고한 자료들
   ├─ 📁 Libraries 
   ├─ 📁 settings 
   ├─ 📁 user
   │  ├─ 📁 inc
   │  ├─ bluetooth.c // 블루투스 통신 설정 코드
   │  ├─ bluetooth.h // bluetooth.c의 헤더 파일
   │  ├─ direction.h // 로봇 방향 관련 헤더 파일
   │  ├─ lcd2.h // TFT LCD 크기 설정 관련 헤더 파일
   │  ├─ main.c // 최종 자율 주행 알고리즘 적용한 main 코드
   │  ├─ motor.c // 릴레이모듈(바퀴) 설정 코드
   │  ├─ motor.h // motor.c의 헤더 파일
   │  ├─ obstacle.c // 장애물 탐지 관련 코드
   │  ├─ obstacle.h // obstacle.c의 헤더 파일
   │  ├─ robot.c // 로봇의 움직임 관련 코드 
   │  ├─ robot.h // robot.c의 헤더 파일
   │  ├─ sensor.c // 적외선 센서 설정 관련 코드
   │  ├─ sensor.h // sensor.c의 헤더 파일
   │  ├─ stm32f10x_it.c 
   │  ├─ trace.c // 지도 저장 및 display 관련 코드
   │  └─ trace.h // trace.c의 헤더 파일
   ├─ flashclear.zip 
   ├─ test.dep
   ├─ test.ewd
   ├─ test.ewp
   ├─ test.ewt
   └─ test.eww
```
### 로봇의 주요 기능
- 스마트폰과 블루투스 통신을 한다.
- 90도씩 방향 전환이 가능하다.
- 장애물을 피하여 설정된 목적지에 도달한다.
- 이동 경로 데이터를 저장한다. 
- 주행을 하면서 이동 경로와 감지되는 장애물을 지도(LCD)에 실시간으로 표시한다.

### 알고리즘 설계도
<img width="600" alt="알고리즘 설계도" src="https://user-images.githubusercontent.com/76769044/210163085-9f384b2c-8c74-4bb5-b0f0-7e05e3f854dc.jpg">

  <details>
  <summary> 장애물 회피 및 목적지 도달을 위한 과정 </summary>
  <div markdown="1">

1. 로봇이 직진 상태일 때 장애물이 없거나 좌방 또는 우방에 있는 경우 <br>
	로봇이 전진하면 된다.
2. 로봇이 직진 상태일 때 장애물이 전방과 좌방에 있는 경우 <br>
	로봇이 오른쪽으로 회전 후 전진한다.
3. 로봇이 직진 상태일 때 장애물이 전방과 우방에 있는 경우<br>
	로봇이 왼쪽으로 회전 후 전진한다.
4. 로봇이 직진 상태일 때 장애물이 전방에만 있는 경우<br>
	로봇이 오른쪽 또는 왼쪽으로 회전 후 전진해야한다. 현재 로봇이 왼쪽으로 많이 와있는 상태(좌우변위 값이 양수)라면 우회전해서 가고, 오른쪽으로 많이 와있는 상태(좌우변위 값이 음수)라면 좌회전을 해서 가도록 한다.
5. 로봇이 우진 상태일 때 장애물이 좌방 또는 좌방&우방에 있는 경우<br>
	좌방의 장애물 때문에 회전하지 못하므로 계속해서 전진한다.
6. 로봇이 좌진 상태일 때 장애물이 우방 또는 우방&좌방에 있는 경우<br>
	우방의 장애물 때문에 회전하지 못하므로 계속해서 전진한다.
7. 로봇이 좌진 상태일 때 장애물이 없거나 전방 혹은 좌방에 있는 경우<br>
	장애물이 더이상 우방에 없으므로 오른쪽으로 회전하여 전진한다. 
8. 로봇이 좌진 상태일 때 장애물이 우방과 전방에 있는 경우<br>
	로봇은 오른쪽으로 회전 후 전진한다. 이때, 로봇이 회전 하고 나면 전방과 좌방에 장애물이 있다고 인식이 될텐데 해당 경우 2번 상황으로 돌아가게 된다. 
9. 로봇이 우진 상태일 때 장애물이 없거나 전방 혹은 우방에 있는 경우<br>
	장애물이 더이상 좌방에 없으므로 왼쪽으로 회전하여 전진한다. 
10. 로봇이 우진 상태일 때 장애물이 좌방과 전방에 있는 경우<br>
	로봇은 왼쪽으로 회전 후 전진한다. 이때, 로봇이 회전 하고 나면 전방과 우방에 장애물이 있다고 인식이 될텐데 해당 경우 3번 상황으로 돌아가게 된다. 

  </div>
  </details>

### 시행착오 및 해결 방법

1. 시간 측정 방법

    📌 로봇이 각 방향에서 (앞, 오른쪽, 왼쪽) 이동하는 동안 걸린 시간을 count 하는 방법에 대해 고민했다.
    - idea1: delay 함수를 이용한다.<br>
    → 문제점: 로봇이 진행하고 있는 경우, 장애물이 인식되어도 delay 때문에 멈추지 않을 수 있다.
    - idea2: time.h 헤더 파일을 이용하여 흐른 시간을 계산한다.<br>
    → 해당 방법을 채택하였고, 방향 설정 함수 안에서 작성을 하였다.

2. 로봇 회전 방법

    📌 로봇을 정확하게 90도 돌릴 수 있는 방법에 대해 고민했다.
    - idea1: 방위각 센서를 이용한다. <br>
    → 예산 범위를 벗어나서 아쉽게도 방위각 센서를 구입하지 못했다.
    - idea2: delay 함수를 이용하여 임의의 시간만큼 회전하게끔 한다.<br>
    → 얼마 만큼 delay를 거는 것이 정확한지 판단하기 어렵다.
    - idea3: Timer로 회전에 필요한 정확한 시간을 정해서 회전한다.<br>
    → code의 복잡도가 높아져서 폐기했다.
    - idea4: 장애물을 만난 상황(앞 센서 인식)~ 회전 끝난 상황(우 센서 인식) 사이의 시간을 time.h 헤더 파일을 이용하여 흐른 시간을 계산한다.<br>
    → 로봇의 무게, 바퀴 상태, 배터리 성능 등에 따라 값이 다 달라 특정하기 어렵다.<br>
    
    현 상황에서 정확하게 90도를 회전하기 위한 최선의 상황은 임의로 delay를 주는 것으로 결론을 내렸다. 

3. 동작 오류

    📌 로봇의 오른쪽 바퀴가 정회전하지 않는다는 오류가 발생했다.
    - 코드에서 해당 릴레이 모듈과 관련된  PC11핀이 잘못된 게 없는지 확인한다.
    - 블루투스 모듈의 결함일 것이라 추측하여 변경하였지만 달라진 게 없었다.
    - 블루투스에 com signal이 잘 들어가지 않을 것이라 추측하고 회로를 분석했다. 
    - 해결: 배터리 부족 문제였다. 보드의 전원 선을 연결하고 동작시키면 문제 없이 잘 된다.

4. 포트 변경

    📌 포트 변경 관련 시행착오가 발생했다.
    - TFT LCD를 사용하려 보니 LCD가 저장소로 Port E를 쓰고 있다.
    - 그래서, 릴레이 모듈과 적외선 센서의 포트를 C로 옮겼다.
    - 릴레이 모듈: Port C 8, 9 ,10 ,11
    - 적외선 센서: Port C 2, 3, 4 (순서대로 앞, 우 , 좌)


### 프로젝트 시연 영상
[<img width="600" alt="시연 영상" src="https://user-images.githubusercontent.com/76769044/210162682-ca573bd6-e268-4d84-b80e-9952fd3285ff.png">](https://photos.app.goo.gl/PiPbDQ116FgrjeBv7)


### 발전방향 및 의의
1. 장애물 탐지 알고리즘 코드 재사용 가능성
  - 순간의 장애물들을 회피하기 위한 코드가 아닌 로봇의 동체를 기준으로 장애물을 만나고 이동하는 모든 상황을 고려한 알고리즘이기 때문에 여러 부문에 이식할 수 있는 장점을 가진다.

2. 감지한 장애물 및 생성된 지도 데이터를 활용한 부가적인 서비스 개발

- 주로 직면하는 장애물 형태 분석 등을 통해 개발자가 해당 데이터를 활용하여 이전 버전보다 더 나은 서비스를 업데이트 할 수 있다.
- 장애물과 충돌시 담당 공무원 등에게 지도데이터를 통해 충돌 알림과 동시에 위치를 보내는 서비스를 도입하여 시각장애인의 안전에 도움을 줄 수 있다.
- 장애물 위치, 모양 등의 데이터를 수집할 수 있기 때문에, 하루 동안 직면한 장애물의 종류를 정리하여 사용자에게 알려주는 서비스 등을 개발할 여지가 많다.

 3. 자율주행 자동차 기능 수행
- 4륜 구동으로 로봇을 제작했기 때문에 기본적으로 장애물을 회피하는 자율주행 자동차의 역할을 가진다.
- 위 기능을 기틀로 하여, 보다 발전적인 자율주행 자동차 개발의 가능성을 확인할 수 있다.

----

자세한 내용은 아래 보고서를 참고해주세요.<br>
[최종 보고서](https://docs.google.com/document/d/1diTTW79o_wZT5trPB3eym0REY6TfK7wClsZOfB5oGHg/edit?usp=sharing)
