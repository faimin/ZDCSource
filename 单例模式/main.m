//
//  main.m
//  单例模式
//
//  Created by 符现超 on 14-3-23.
//  Copyright (c) 2014年 符现超. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressBook.h"


int main(int argc, const char * argv[])
{

    @autoreleasepool {
        AddressBook *book1=[AddressBook shareInstanse];
        book1.phone=@"2353253634";
        
        AddressBook *book2=[AddressBook shareInstanse];
        AddressBook *book3=[AddressBook shareInstanse];
        
    
        [book1 release];
    
    
    
    }
    return 0;
}

