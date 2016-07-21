#import "FRD3DBarChartViewController.h"


typedef enum {
    kEasingMethodLinear,
    kEasingMethodQuadraticIn,
    kEasingMethodQuadraticOut,
    kEasingMethodQuadraticInOut,
    kEasingMethodCubicIn,
    kEasingMethodCubicOut,
    kEasingMethodCubicInOut,
    kEasingMethodQuarticIn,
    kEasingMethodQuarticOut,
    kEasingMethodQuarticInOut,
    kEasingMethodQuinticIn,
    kEasingMethodQuinticOut,
    kEasingMethodQuinticInOut,
    kEasingMethodExponentialIn,
    kEasingMethodExponentialOut,
    kEasingMethodExponentialInOut,
    kEasingMethodCircularIn,
    kEasingMethodCircularOut,
    kEasingMethodCircularInOut,
    kEasingMethodSinIn,
    kEasingMethodSinOut,
    kEasingMethodSinInOut,
} kEasingMethods;

@interface FRD3DBarChartViewController (Easing)

-(float) easingWithMethod:(kEasingMethods)method currentTime:(NSTimeInterval) t  startValue:(float) b changeInValue:(float) c duration:(NSTimeInterval) d;

@end
