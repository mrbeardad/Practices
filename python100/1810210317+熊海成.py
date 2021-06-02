#!/usr/bin/env python
# -*- coding: utf-8 -*-

import wordcloud
import jieba

def main():
    # 机器没宋体
    text = '你他娘的可真是可人才'
    wc = wordcloud.WordCloud('SourceHanSansCN-Medium.otf', background_color='red', max_words=20)
    wc.generate(' '.join(jieba.lcut(text)))
    wc.to_file('test.png')

if __name__ == '__main__':
    main()
