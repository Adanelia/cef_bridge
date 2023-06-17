import os


project_name = 'cef_bridge'

output_path = 'bin/'

def add_sources(sources, dir):
    for f in os.listdir(dir):
        if f.endswith(".cpp"):
            sources.append(dir + "/" + f)

sources = []
add_sources(sources, 'src')

libs = [
    'kernel32.lib', 'user32.lib', 'gdi32.lib', 'winspool.lib', 'comdlg32.lib', 'advapi32.lib', 'shell32.lib', 'ole32.lib', 'oleaut32.lib', 'uuid.lib',
    'libcef.lib', 'cef_sandbox.lib', 'libcef_dll_wrapper.lib'
]
libpath = ['cef_binary/build/libcef_dll_wrapper']
ccflags = []
cpppath=['cef_binary']


# debug
# ccflags=["-EHsc", "-D_DEBUG", "-MTd", "-D_WINDOWS", "-D_UNICODE", "-DUNICODE"]
# libpath.append('cef_binary/Debug')

# release
ccflags=["-O2", "-EHsc", "-DNDEBUG", "-MT", "-D_WINDOWS", "-D_UNICODE", "-DUNICODE"]
libpath.append('cef_binary/Release')


# --- cef_subprocess ---
Program(output_path + 'cef_subprocess', 'cef_subprocess/main.cpp', LIBS=libs, LIBPATH=libpath, CCFLAGS=ccflags, CPPPATH=cpppath)

# --- cef_bridge ---
SharedLibrary(output_path + project_name, sources, LIBS=libs, LIBPATH=libpath, CCFLAGS=ccflags, CPPPATH=cpppath)
