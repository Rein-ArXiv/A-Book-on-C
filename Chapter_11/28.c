/* Chapter 11 exercise 28 */

/* 이 장에서 소개했던 마지막 makefile은 실제로 사용되는 것이다. 이것에 대해 자
 * 세히 설명했지만 make를 사용하지 않았다면, 쉽게 이해하기 힘들 것이다. 이 유틸
 * 리티가 생소하다면, makefile을 다음과 같이 작성한 후에 make 명령을 수행해
 * 보아라.

    # Experiment with the make command.
    
    go: hello date list
        @echo Goodbye!
    hello:
        @echo Hello!
    date:
        @date; date; date
    list:
        @pwd; ls

 * @ 문자를 삭제하면 어떻게 되겠는가? hello나 date라는 파일이 없다면, 어떻게
 * 되겠는가?
 */