//
//  LISAppDelegate.m
/*
Copyright 2012 UCLan (University of Central Lancashire)

Licenced under the BSD 2-Clause Licence.
You may not use this file except in compliance with the License.
You may obtain a copy of the License at:

       http://opensource.org/licenses/bsd-license.php

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#import "LISAppDelegate.h"

#import "LISRootViewController.h"

@implementation LISAppDelegate

@synthesize window = _window;
@synthesize navigationController = _navigationController;


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    //setup for accessibility
    BOOL UIAccessibilityIsVoiceOverRunning();
    
    //check if accessibility is on and if so load the accessibility version
    if (UIAccessibilityIsVoiceOverRunning(TRUE)) {
        // Override point for customization after application launch.
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
            LISRootViewController *masterViewController = [[LISRootViewController alloc] initWithNibName:@"LISRootViewControllerAccess" bundle:nil];
            self.navigationController = [[UINavigationController alloc] initWithRootViewController:masterViewController];
            self.window.rootViewController = self.navigationController;
        } else {
            //not setup for accessibility on the ipad yet, possible future development
            LISRootViewController *masterViewController = [[LISRootViewController alloc] initWithNibName:@"LISRootViewController_iPad" bundle:nil];
            self.navigationController = [[UINavigationController alloc] initWithRootViewController:masterViewController];
            self.window.rootViewController = self.navigationController;
        }
    }
    
    else {
        // Override point for customization after application launch.
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
            LISRootViewController *masterViewController = [[LISRootViewController alloc] initWithNibName:@"LISRootViewController" bundle:nil];
            self.navigationController = [[UINavigationController alloc] initWithRootViewController:masterViewController];
            self.window.rootViewController = self.navigationController;
        } else {
            LISRootViewController *masterViewController = [[LISRootViewController alloc] initWithNibName:@"LISRootViewController_iPad" bundle:nil];
            self.navigationController = [[UINavigationController alloc] initWithRootViewController:masterViewController];
            self.window.rootViewController = self.navigationController;
        }
    }
    
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end