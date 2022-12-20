import math
with open("4_7py.dat",'w') as f:
    print("#x y u",file=f)

def func(x,y,u,v,i):
    fx = i-120.0*pow(y, 3.0)*u*(x-115.0)-40.0*pow(v, 4.0)*(x+12.0)-0.24*(x-10.613)
    fy = ((0.1*(25.0-x))/(math.exp((25-x)/10.0)-1.0))*(1-y)-4.0*math.exp((-x)/18.0)*y
    fu = 0.07*math.exp((-x)/20.0)*(1.0-u)-1/(math.exp((30.0-x)/10.0)+1.0)*u
    fv = ((0.01*(10.0-x))/(math.exp((10.0-x)/10.0)-1.0))*(1.0-v)-0.125*math.exp(-x/80.0)*v
    return (fx,fy,fu,fv)

def runge_kutta(nt,dt,x0,y0,u0,v0,i0,a,f):
    F = open("4_7py.dat",'a')
    t = 0
    x = x0
    y = y0
    u = u0
    v = v0

    for n in range(int(nt)):
        i = i0 + a * math.sin(2.0*math.pi*f*t)
        (kx1,ky1,ku1,kv1) = func(x             ,y             ,u             ,v             ,i)
        (kx2,ky2,ku2,kv2) = func(x + dt*kx1/2.0,y + dt*ky1/2.0,u + dt*ku1/2.0,v + dt*kv1/2.0,i)
        (kx3,ky3,ku3,kv3) = func(x + dt*kx2/2.0,y + dt*ky2/2.0,u + dt*ku2/2.0,v + dt*kv2/2.0,i)
        (kx4,ky4,ku4,kv4) = func(x + dt*kx3    ,y + dt*ky3    ,u + dt*ku3    ,v + dt*kv3    ,i)

        x += dt*(kx1 + 2.0*kx2 + 2.0*kx3 + kx4)/ 6.0
        y += dt*(ky1 + 2.0*ky2 + 2.0*ky3 + ky4)/ 6.0
        u += dt*(ku1 + 2.0*ku2 + 2.0*ku3 + ku4)/ 6.0
        v += dt*(kv1 + 2.0*kv2 + 2.0*kv3 + kv4)/ 6.0
        t = n*dt

        if(t > 100):
            print(x,y,u,file=F)
    F.close()

def main():
    dt = 0.01
    t = 1000.0
    nt = t/dt

    x0 = -12.0
    y0 = 0.1
    u0 = 0.1
    v0 = 0.5

    i0 = 20.0
    a = 40.0
    f = 0.3

    runge_kutta(nt, dt, x0, y0, u0, v0, i0, a, f)

if __name__ == "__main__":
    main()