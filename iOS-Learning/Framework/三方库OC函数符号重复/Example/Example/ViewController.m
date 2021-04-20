//
//  ViewController.m
//  Example
//
//  Created by YoloMao on 2021/3/31.
//

#import "ViewController.h"
#import <objc/runtime.h>
//@import APod;
//@import BPod;

@interface ViewController ()

@end

@implementation ViewController

extern void test(void);

//Cocoapods三方库以名称顺序编译；
//在静态链接过程中，如果有相同符号，则会编译报错；
//在动态链接过程中，如果有相同符号，则会忽略掉第一个之外的相同符号。
- (void)viewDidLoad {
    [super viewDidLoad];
    [NSString performSelector:NSSelectorFromString(@"log")];
    [objc_getClass("AAA") performSelector:NSSelectorFromString(@"log")];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    test();
}

@end
