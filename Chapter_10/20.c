/* Chapter 10 exercise 20 */

/* polish 프로그램의 evaluate() 함수에 다음과 같은 문장이 있다.

    case operator:
        d2 = pop(&eval)
        d1 = pop(&eval)

 * 이 문장을 다음과 같이 수정한다면 어떻게 되겠는가?

    case operator:
        d1 = pop(&eval)
        d2 = pop(&eval)

 * 어떤 폴리시 수식에 대해서는 정확히 동작하고, 어떤 수식에 대해서는 그렇지 않
 * 을 것이다. 그 이유를 설명하여라.
 */