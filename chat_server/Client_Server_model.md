## 클라이언트/서버 구조
1. 멀티 프로세스 기반의 서버
  - 파이프라인을 이용한 통신
2. 멀티 쓰레드 기반의 서버
  - 임계영역 주의
3. IO 멀티플렉싱
  - 멀티플렉싱 : 하나의 통신채널을 통해서 둘 이상의 데이터를 전송하는데 사용되는 기술
  - IO 멀티플렉싱 기반의 서버는 select 함수를 이용하여 하나의 프로세스가 여러개의 소켓을 관리하는 서버이다.

