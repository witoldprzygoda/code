// kod


int main() {
    unique_ptr<ResFactory> fabryka(new LowResFactory);
    unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv();
    unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();

    fabryka.reset(new HighResFactory);
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();
}

