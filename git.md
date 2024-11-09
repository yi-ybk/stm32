[TOC]

[教程](https://www.bilibili.com/video/BV19J411j7SZ?spm_id_from=333.788.videopod.episodes&vd_source=675c025be7e8b947d00b503859eb0971)

# 基础操作

## 初始化

```bash
git init
```

 

创建新的git仓库

## 克隆仓库

```bash
git clone
```

在本地克隆一个远程仓库

## 查看文件

```bash
dir (windows)
```

```bash
ls (linux ，windows)
```



## 链接远程仓库

```bash
git remote add [为仓库命名]  [仓库地址]
```



## 删除链接的远程仓库

```bash
git remote remove + [仓库名称]
```



## 查看链接的所有远程仓库

```bash
git remote -v
```



## 设定默认的远程仓库

```bash
git remote set-default [仓库名称]
```



## 改变链接的远程仓库

```bash
git remote set-url [已经存在的仓库名称]  [新仓库地址]
```



## 与远程仓库同步

```bash
git reset --hard origin/main
```

## 推送

- `git push`：
  
  - 这个命令用于将当前分支的更改推送到远程仓库的对应分支。
  - 如果之前已经设置过上游分支（upstream branch），即通过 `git push -u` 命令，那么之后只需要使用 `git push` 就可以将更改推送到远程仓库。
  - 如果没有设置上游分支，需要指定远程仓库和分支，例如 `git push <remote> <branch>`。
  
  **注：**链接多个远程仓库时，若无指定仓库，则每个仓库都会推送
- `git push -u`：
  - 这个命令用于将当前分支的更改推送到远程仓库，并设置远程仓库的对应分支为上游分支。
  - `-u` 参数是 `--set-upstream` 的简写，它的作用是将本地分支和远程分支关联起来。
  - 一旦设置了上游分支，之后只需要使用 `git push` 就可以推送更改，Git 会自动知道想要推送到哪个远程分支。
  - 例如，如果有一个本地分支 `feature`，并且想要推送到远程仓库的 `origin` 上的 `feature` 分支，可以使用 `git push -u origin feature`。

## 删除

```bash
git rm [文件]
```

```bash
git rm -r [目录]
```



## 跟踪远程

```bash
git branch --set-upstream-to=[仓库名称]/[远程分支名称] [本地分支名称]
```



## 拉取远程分支的代码

```bash
git pull [仓库名称] [分支]
```

(拉取到仓库最新状态,**注:**拉取时,若在远程仓库删除文件,本地仓库对应文件会**被删除**)

## 查看当前仓库版本（包括之前版本，不包括之后的版本）

```bash
git log
```

- 出现 **:** 是因为内容过多一屏违法完全显示,可以往下翻,按 Q 键退出

```bash
git log --prety=oneline (以简短的方式显示)
```



## 版本回退

- *HEAD指针 指向最新版本 ,HEAD~n指HEAD的前第n个版本*

* *版本回退不会删除版本*

```bash
git reset --hard 版本号(git relog查看)
```

或

```bash
git reset --hard HEAD~n
```



## 工作区与版本库

- 本地git仓库即为工作区

- 本地git仓库内的  *.git* 隐藏文件夹即为版本库 

  - 版本库内有  *暂存区* 

  - ```bash
     git add [文件]/[目录]  （可多个）
     ```

        即为添加修改到暂存区
  
  - ```bash
     git commit
     ```
     
      即为将**暂存区**内添加的修改创建版本记录
     
     （*未添加到暂存区的修改不会被提交到版本记录内*）

## 查看当前工作树状态

```bash
git status
```

​	

## 撤销修改

```bash
git checkout --[文件名]
```

- 只能撤销 未add 到暂存区的修改
- 已经add的修改要先执行 git reset HEAD [文件名] 撤销add
- 已经commit的要进行 git reset --hard HEAD~n 版本回退

## 丢弃已经add到暂存区的修改

```bash
git reset HEAD [文件名]
```



## 对比文件的不同

```bash
git diff HEAD -- [文件名]
```



```c
--- ****** (对应 HEAD版本 的文件) (要比较的版本1)
+++ ****** (对应 当前工作区内 的文件) (要比较的版本2)
********** (共同的内容)   
    
+/- ********** (不同的内容)   
```

```bash
git diff [要比较的版本1] [要比较的版本2] -- [文件名]
```



# gti分支

## 查看分支

```bash
git branch
```



- 可以查看共有几个分支,且当前在哪个分支工作(HEAD指针移动到分子上 )

## 创建并切换分支

```bash
git checkout -b [分支名称]
```



## 切换分支

```bash
git checkout [分支名称]
```



## 删除分支

```bash
git branch -d [分支名称]
```



## 合并分支到当前分支

```bash
git merge [要合并的分支名称]
```

  (快速合并,即移动 *当前分支指针*,不执行新提交,只是合并内容)

- 合并到当前分支

```bash
git merge --no-ff -m "注释"
```

 [分支名称] (禁用快速合并,即合并完后执行一次提交) (修理bug时可用)

***删除分支后仍然能用 git log --prety=onelineit  查看修改记录***

## 切换分支后提交

***编辑同一个文件**,若在 dev分支 提交后,再切换到 master分支 提交,则无法将 dev分支和 master分支 **快速合并*** (合并冲突)

- 要手动解决冲突后,再add并commit

*编辑文件A,在dev分支提交,再切换到master分支,编辑文件B再 提交,再合并dev分支和master分支*

- 可以成功合并,结果为执行一次新的提交,而**不是快速合并**   

## 查看git的分支树

```bash
git log --graph --pretty=oneline
```



## 保存现场

```bash
git stash
```



## 查看保存的现场

```bash
git stash list
```



## 恢复保存的现场

```bash
git stash pop
```



# ssh密钥

windows：打开 git bash，输入ssh-keygen指令，创建ssh密钥

linux ： 终端输入 ssh-keygen

(**若无法使用ssh密钥,在 C:\ 用户\ (用户名)\ .ssh \config(无则创建)  中,写入以下指令 **)

```c
Host github.com

HostName ssh.github.com

User git 

Port 443
```

linux同理 , 注:linux的.ssh目录在主目录的隐藏文件夹
