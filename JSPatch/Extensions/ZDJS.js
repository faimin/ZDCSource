// JSPatch文档： https://github.com/bang590/JSPatch/wiki/JSPatch-%E5%9F%BA%E7%A1%80%E7%94%A8%E6%B3%95#%E5%B8%B8%E9%87%8F%E6%9E%9A%E4%B8%BE
// 宏处理： https://github.com/bang590/JSPatch/issues/109
// https://github.com/bang590/JSPatch/issues/292
// 常见问题解答： https://github.com/bang590/JSPatch/wiki/JSPatch%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E8%A7%A3%E7%AD%94

require('ReactiveCocoa,UIView,IQKeyboardManager,RACCommand,UserInfo,RACSignal,DiscoverDetailBusiness,DDHUD,NSNotificationCenter,BFTask,NSString,DDJPExtension')

require('JPEngine').addExtensions(['JPNumber', 'DDJPExtension'])

defineClass('DiscoverDetailViewController', {

    // 方法1
    buildUI: function() {
        self.super().buildUI();
        
        if (self.articleInfo().articleType() == 7000) {
            self.setTitle("攻略详情");
        } else {
            self.setTitle("文章详情");
        }
        
        self.tableView().setTableFooterView(UIView.alloc().init());
        self.tableView().tableHeaderView().setHidden(YES);
        self.setEnableRefreshAccessory(YES);
        self.setEnableLoadMoreAccessory(YES);
        
        var UIControlEventTouchUpInside = 1 << 6;
        self.strategyPublishButton().addTarget_action_forControlEvents(self, "goStrategyVC", UIControlEventTouchUpInside);
        IQKeyboardManager.sharedManager().disableInViewControllerClass(self.class());
        
        self.commandAction();
        
        _ADoffsetY = 90;
    },

    // 方法2
    commandAction: function() {
        var weakSelf = __weak(self);
        var collectCommand = RACCommand.alloc()
        .initWithSignalBlock(block("id", function(input) {
            var strongSelf = __strong(weakSelf)

            if (!UserInfo.isUserLogin()) {
                strongSelf.pushLoginView()
                return RACSignal.empty()
            }

            var ddm = strongSelf.business().model()

            if (ddm.canBeDel() == 1) {
                strongSelf.deleteDigest(ddm.digestDetail().digestId())
            }

            strongSelf.business().motifyCollect_isCollect(strongSelf.articleInfo().articleID(), !strongSelf.bCollect())
            .continueWithBlock(block("BFTask *", function(task){
                var strongSelf = __strong(weakSelf)

                if (task.error()) {
                    DDHUD.alertWithMessage_inView(task.error().localizedDescription(), strongSelf.view())
                } else {
                    strongSelf.setBCollect(!strongSelf.bCollect())
                    if (strongSelf.bCollect()) {
                        DDHUD.alertWithMessage_inView("收藏成功", strongSelf.view())
                    } else {
                        DDHUD.alertWithMessage_inView("取消收藏成功", strongSelf.view())
                    }

                    // var dict = require('NSDictionary').dictionaryWithObjectsAndKeys(strongSelf.articleInfo().articleID(), "digestId", strongSelf.bCollect(), "isStoreUp").toJS()
                    var dict = {"digestId":strongSelf.articleInfo().articleID(), "isStoreUp":strongSelf.bCollect()}
                    NSNotificationCenter.defaultCenter().postNotificationName_object("StoreUpStatusChangeNotificaion", dict)
                }
                return null
            }))

            return RACSignal.empty()                
        
        }))

        self.collectButton().setRac__command(collectCommand)

        // 是否收藏
        RACObserve(self, self, "bCollect")
        .map(block("id", function(value){
            if (value == 1) {
                return "star_hover"
            } else {
                return "star"
            }
        }))
        .subscribeNext(block("id", function(value){
            var strongSelf = __strong(weakSelf)
            strongSelf.collectButton().setImage_imageWithRenderingMode(require('UIImage').imageNamed(value), 1)
        }))


        RACObserve(self, self.business(), "error")
        .subscribeNext(block("id", function(value){
            var strongSelf = __strong(weakSelf)

            if (!value) {
                strongSelf.navigationItem().setRightBarButtonItem(strongSelf.collectButton())
            } else {
                strongSelf.navigationItem().setRightBarButtonItem(null)
            }
        }))


        // 点赞
        var praiseCommand = RACCommand.commandWithSignalBlock(block("id", function(input){
            var strongSelf = __strong(weakSelf)

            var ddm = strongSelf.business().model()
            var num = strongSelf.articleInfo().articleType()
            //.integerValue()
            // js默认会把NSNumber类型转成数值类型，toOCNumber(数字)方法可以转换成NSNumber类型
            require('DiscoverChapterListBusiness').praiseDigestWithDigestId_targetSource(ddm.digestDetail().digestId(), toOCNumber(num))
            .continueWithBlock(block("BFTask *", function(task){
                var strongSelf = __strong(weakSelf)
                if (task.error()) {
                    DDHUD.alertWithMessage_inView(task.error().localizedDescription(), strongSelf.view())
                } else {
                    var request = task.result()
                    var exp
                    var integral

                    if (request.experience() > 0) {
                        // exp = NSString.stringWithFormat("经验+%@", request.experience())
                        exp = "经验+" + request.experience()
                    }

                    if (request.integral() > 0) {
                        integeral = "积分" + request.integral()
                    }

                    var praiseContent = "点赞成功" + exp + integral
                    DDHUD.alertWithMessage_inView(praiseContent, strongSelf.view())

                    strongSelf.inputView().setBCollect(YES)
                    strongSelf.inputView().showAnimation()
                    strongSelf.topCnt().setText((ddm.digestDetail().topCnt()+1)+"")
                    strongSelf.setBPraise(YES)
                }

                return null
            }))

            return RACSignal.empty()
        }))

        self.inputView.setRac__command(praiseCommand)

        console.log("\n==================执行了===============")
            
    },


});
