# fenghao
Eight number   
–３×３の盤面、各マスに１〜８のピース、１カ所は空白  
–数字付きピースを隣接する空マスへ移動させ、盤面を終了状態にする  
–ピースの移動は１ピースずつとする  
1 3 2                          1 3 2    
4 5 6                          4 5    
7 8         input 6 ->         7 8 6  
自動モードと入力モード  

1.0    5x5行列のバージョン（二维）　自動モードと入力モード　　入力例 1 4 3 7 2 6 8 5 0  自動モードは入力行列から目標まで探索します（幅探索bfs）  
重複チェックは　mapのkey-valve  
2.0    自動モードだけ　一维stringのバージョン　入力例143726850  自動モードは入力行列から目標まで探索します 幅探索(bfs）  
重複チェックはCantor expansion  
2.1    自動モードだけ　一维stringのバージョン　入力例143726850  自動モードは目標行列から入力まで探索します 幅探索(bfs）  
重複チェックはCantor expansion  
2.2    自動モードだけ　一维stringのバージョン　入力例143726850  自動モードは目標行列から全部移動できる行列を計算して、保存します。後は探す  
