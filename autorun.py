import os
import subprocess
import time
import logging

# 配置日志记录
logging.basicConfig(level=logging.INFO, format='[%(levelname)s] %(message)s')

def log_file_info(file_path):
    file_time = os.path.getmtime(file_path)
    formatted_time = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(file_time))
    logging.info(f'File: {file_path}, Last Modified: {formatted_time}')

# 记录开始时间
start_time = time.time()

# 进入 build 目录
os.chdir('build')
logging.info('Changed directory to build')

# 执行 cmake ..
logging.info('Running cmake')
# 判断平台 如果是Windows系统，使用cmake .. -G "Ninja"，否则使用cmake ..
if os.name == 'nt':
    logging.info('Detected Windows system, using Ninja generator')
    subprocess.run(['cmake', '..','-DCMAKE_BUILD_TYPE=Release', '-G', 'Ninja'])
else:
    logging.info('Detected non-Windows system, using default generator')
    subprocess.run(['cmake', '..'])

# 执行 make
logging.info('Running make')
if os.name == 'nt':
    subprocess.run(['ninja','-j16'])
else:
    subprocess.run(['make', '-j16'])

# 找到最新生成或修改的二进制文件列表 并输出信息
# 通过 os.listdir() 获取 build 目录下的所有文件
files = os.listdir()
# 通过 filter() 函数过滤出所有二进制文件
# 在Windows系统中，二进制文件的扩展名为 .exe
# 在非Windows系统中，二进制文件没有扩展名
if os.name == 'nt':
    bin_files = list(filter(lambda x: x.endswith('.exe'), files))
else:
    # 看是否可以执行
    bin_files = list(filter(lambda x: os.access(x, os.X_OK), files))
    
# 对二进制文件列表进行排序，以最新修改时间为排序依据
bin_files.sort(key=lambda x: os.path.getmtime(x), reverse=True)
# 将最新修改时间在start_time之后的二进制文件输出
change_files = []
for file in bin_files:
    if os.path.getmtime(file) > start_time:
        change_files.append(file)
        log_file_info(file)
# 如果没有找到最新
if len(change_files) == 0:
    logging.info('No new binary file generated')