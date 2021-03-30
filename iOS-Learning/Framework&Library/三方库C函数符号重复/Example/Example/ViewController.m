//
//  ViewController.m
//  Example
//
//  Created by YoloMao on 2021/3/30.
//

#import "ViewController.h"
#import <NodeMediaClient/NodeMediaClient.h>

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIView *playerView;
@property (nonatomic, strong) NodePlayer *node;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NodePlayer *node = [[NodePlayer alloc] init];
    node.playerView = self.playerView;
    node.inputUrl = @"rtmp://58.200.131.2:1935/livetv/gdtv";
    self.node = node;
}

- (IBAction)playAction:(UIButton *)sender {
    [self.node start];
}

@end
