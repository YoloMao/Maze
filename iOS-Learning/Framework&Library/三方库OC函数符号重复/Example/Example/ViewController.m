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

//Cocoapods三方库以名称顺序编译;
//C函数相同，以最早链接的为准;
//OC函数相同符号(非Category)，如果在二进制以及静态库中重复的话，会报编译错误；如果在动态库中，编译器以最早链接的为准;
//OC函数相同符号(Category)，以最后一个链接的为准;

- (void)viewDidLoad {
    [super viewDidLoad];
    [NSString performSelector:NSSelectorFromString(@"log")];
    [objc_getClass("AAA") performSelector:NSSelectorFromString(@"log")];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    test();
}

@end
